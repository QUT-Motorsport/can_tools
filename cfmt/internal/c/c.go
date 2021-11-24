package c

import (
	"errors"
	"fmt"
	"github.com/cfmt/internal/helpers"
	"os/user"
	"time"
)
import "github.com/cfmt/internal/structures"

const parse_spec string = "void Parse_%v_%v(%v){\n"
const compose_spec string = "%v_%v_t Compose_%v_%v(%v){\n"
const func_close string = "}\n"

func ClangToType(_type string) (string, error) {
	switch _type {
	case "int8":
		return "int8_t", nil
	case "uint8":
		return "uint8_t", nil
	case "int16":
		return "int16_t", nil
	case "uint16":
		return "uint16_t", nil
	case "int32":
		return "int32_t", nil
	case "uint32":
		return "uint32_t", nil
	case "int64":
		return "int64_t", nil
	case "uint64":
		return "uint64_t", nil
	case "float":
		return _type, nil
	case "double":
		return _type, nil
	default:
		return "", errors.New("unable to parse data type")
	}
}

func ClangHeaderGuard(family string) []byte {
	name, err := user.Current()
	if err != nil{
		panic(err)
	}
	return []byte(fmt.Sprintf("#ifndef _%v_CAN_MESSAGES_H_\n#define _%v_CAN_MESSAGES_H_\n\n// Generated on: %v\n// By: %v\n\n", family, family, time.Now(), name.Username))
}

func ClangEndif() []byte {
	return []byte("#endif")
}

func ClangMessageStruct(xml structures.CanXml) ([]byte, error) {
	family := xml.Family
	var result string
	for m := 0; m < len(xml.Messages); m++ {
		message := xml.Messages[m]

		result += fmt.Sprintf("// %v | %v command\n", family, message.Name)
		result += fmt.Sprintf("typedef struct %v_%v_t {\n", family, message.Name)
		sumBits := 0
		compose, parse, sumBits := getVariables(message.Variables)
		result += fmt.Sprintf("\tuint32_t id;\n\tuint8_t data[%v];\n", sumBits/8)
		result += fmt.Sprintf("} %v_%v_t;\n\n", family, message.Name)

		result += fmt.Sprintf("%v_%v_t Compose_%v_%v(%v);\n", family, message.Name, family, message.Name, compose)
		result += fmt.Sprintf("void Parse_%v_%v(%v);\n\n", family, message.Name, parse)
	}
	return []byte(result), nil
}

func ClangCFile(xml structures.CanXml) []byte {
	var result string
	result += fmt.Sprintf("#include \"%v_can_messages.h\"\n\n", xml.Family)
	for i := 0; i < len(xml.Messages); i++ {
		// Get Variables for function decs
		compose, parse, _ := getVariables(xml.Messages[i].Variables)
		result += fmt.Sprintf(compose_spec, xml.Family, xml.Messages[i].Name, xml.Family, xml.Messages[i].Name, compose)
		result += func_close
		result += fmt.Sprintf(parse_spec, xml.Family, xml.Messages[i].Name, parse)
		result += func_close + "\n"
	}
	return []byte(result)
}

func getVariables(variables []structures.Vars) (string, string, int) {
	var compose =""
	var parse = "uint8_t* data"
	sumBits := 0
	for v := 0; v < len(variables); v++ {
		if v == 0 {
			parse += ", "
		}
		sumBits += variables[v].Size
		typeName, err := ClangToType(variables[v].Type)
		helpers.Check(err)
		compose += fmt.Sprintf("%v %v, ", typeName, variables[v].Name)
		parse += fmt.Sprintf("%v* %v, ", typeName, variables[v].Name)

		if v == len(variables) - 1 {
			compose = compose[:len(compose) - 2]
			parse = parse[:len(parse) - 2]

		}
	}
	if sumBits > 64 {
		err := errors.New("invalid message format, length > 64 bits")
		panic(err)
	}
	return compose, parse, sumBits
}
