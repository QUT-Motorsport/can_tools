package structures

type CanXml struct {
	Family   string
	Messages []Msgs
}

type Vars struct {
	Name   string
	Type   string
	Size   int
	Scalar float64
}

type Msgs struct {
	Name      string
	Id        uint32
	Variables []Vars `yaml:"vars"`
}
