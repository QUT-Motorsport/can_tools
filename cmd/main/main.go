package main

import (
	"fmt"
	"github.com/cfmt/internal/c"
	"github.com/cfmt/internal/helpers"
	"github.com/cfmt/internal/structures"
	"gopkg.in/yaml.v2"
	"os"
	"path/filepath"
	"regexp"
	"sync"
)

func main() {
	pathS, err := os.Getwd()
	helpers.Check(err)
	var files []string
	filepath.Walk(pathS+"/messages/", func(path string, f os.FileInfo, _ error) error {
		if !f.IsDir() {
			r, err := regexp.MatchString("yml", f.Name())
			if err == nil && r {
				files = append(files, f.Name())
			}
		}
		return nil
	})

	var parseWait sync.WaitGroup

	for i := 0; i < len(files); i++ {
		parseWait.Add(1)
		go ParseFile(files[i], &parseWait)
	}

	parseWait.Wait()
	fmt.Println("Done Parsing Files")
}

func ParseFile(filename string, parseWait *sync.WaitGroup) {
	defer parseWait.Done()
	fmt.Printf("Parsing Filename: %v\n", filename)
	fileData, err := os.ReadFile("./messages/" + filename)
	helpers.Check(err)
	var m structures.CanXml

	err = yaml.Unmarshal(fileData, &m)
	helpers.Check(err)
	pwd, _ := os.Getwd()
	path := fmt.Sprintf("%v/out/", pwd)
	name := fmt.Sprintf("%v_can_messages", m.Family)
	os.WriteFile(path+name+".h", []byte(""), os.FileMode(0777))
	os.WriteFile(path+name+".c", []byte(""), os.FileMode(0777))

	header, err := os.OpenFile(path+name+".h", os.O_RDWR, 0777)
	helpers.Check(err)
	header.Write(c.ClangHeaderGuard(m.Family))

	// Create Message Structure
	structs, err := c.ClangMessageStruct(m)
	helpers.Check(err)
	header.Write(structs)
	header.Write(c.ClangEndif())

	cfile, err := os.OpenFile(path+name+".c", os.O_RDWR, 0777)
	helpers.Check(err)
	cfile.Write(c.ClangCFile(m))
}
