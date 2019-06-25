#Printing Variables
```
fmt.Println("My favorite number is", rand.Intn(10), " Horray")
fmt.Printf("Now you have %g problems.\n", math.Sqrt(7))
```

#Type comes after variable name
```
var result int
var temp = 7
func add(x int, y int) int
```

#grouping types
```
x int, y int == x, y int
func add(x int, y int) int == func add(x, y int) int
```

#multiple returns
```
func swap(x, y string) (string, string)
...
a, b := swap("hello", "world")
```

#initializers for vars; type can be omitted if so
```
var i, j string = "no", "yes" == var i, j = "no", "yes"
```

#var declaration shorthand inside function ONLY
```
k := 3 == var k = 3
```

#constants
```
const Pi = 3.14
//or
const (
	Pi = 3.14
	World = "世界"
)
```

#basic for loop - declared variables only in scope of for loop
```
for i := 0; i < 10; i++ {
	sum += i
}
```

#optional parts of for loop - this is basically a while loop
```
for ; sum < 1000; {
	sum += sum
}
//or
for sum < 1000 {
	sum += sum
}
```

#if statement local var - also carries over to else or else if
```
if v := math.Pow(x, n); v < lim {
	return v
}
```

#switches - no breaks, not only ints
```
switch os := runtime.GOOS; os {
	case "darwin":
		fmt.Println("OS X.")
	case "linux":
		fmt.Println("Linux.")
	default:
		// freebsd, openbsd,
		// plan9, windows...
		fmt.Printf("%s.\n", os)
}
```

#switch without a condition is same as switch true
```
switch {
	case t.Hour() < 12:
		fmt.Println("Good morning!")
...
```

#defer - pushes to stack and waits till encasing function returns
```
func main() {
	fmt.Println("counting")

	for i := 0; i < 10; i++ {
		defer fmt.Println(i)
	}

	fmt.Println("done")
}
```
CONSOLE
```
counting
done
9
8
...
```

#pointer declaration
```
i := 42
p := &i         // point to i
fmt.Println(*p) // read i through the pointer
```

#structs
```
type Vertex struct {
	X int
	Y int
}

v := Vertex{1, 2}
v.X = 4
p := &v
p.X = 19
```

#struct declarations
```
v2 = Vertex{X: 1}  // Y:0 is implicit
v3 = Vertex{}      // X:0 and Y:0
```

#arrays - size if part of type so it cannot be resized
```
var a [2]string
primes := [6]int{2, 3, 5, 7, 11, 13}
```

#slice - dynamically sized array with [lower bound:upper bound]
```
primes := [6]int{2, 3, 5, 7, 11, 13}
//includes the lower bound, but excludes the upper bound. i.e index 1 to 3
var s []int = primes[1:4]
```
CONSOLE
```
[3,5,7]
```

#slices are pointers are will change the underlying data
```
names := [4]string{
	"John",
	"Paul",
	"George",
	"Ringo",
}

b := names[1:3]

b[0] = "XXX"
fmt.Println(names)
```
CONSOLE
```
[John, XXX, George, Ringo]
```

#slice literal is like array literal without length
```
r := []bool{true, false, true, true, false, true}

s := []struct {
	i int
	b bool
}{
	{2, true},
	{3, false},
	{5, true},
	{7, true},
	{11, false},
	{13, true},
}
```
CONSOLE
```
[true false true true false true]
[{2 true} {3 false} {5 true} {7 true} {11 false} {13 true}]
```

#reslicing 
	- len is the number of elements in slice
	- cap is the number of elements in the underlying array
```
s := []int{2, 3, 5, 7, 11, 13}

// Slice the slice to give it zero length.
s = s[:0]

// Extend its length.
s = s[:4]

// Drop its first two values.
s = s[2:]

fmt.Printf("len=%d cap=%d %v\n", len(s), cap(s), s)
```
CONSOLE
```
len=6 cap=6 [2 3 5 7 11 13]
len=0 cap=6 []
len=4 cap=6 [2 3 5 7]
len=2 cap=4 [5 7]
```

#make and dynamically sized arrays - allocated a zeroed array and returns a slice that refers to it
```
// len(a)=5
a := make([]int, 5)

// len(b)=0, cap(b)=5
b := make([]int, 0, 5)

c := b[:2]

d := c[2:5]
```
CONSOLE
```
a len=5 cap=5 [0 0 0 0 0]
b len=0 cap=5 []
c len=2 cap=5 [0 0]
d len=3 cap=3 [0 0 0]
```

#slice can contain any type including other slices
```
board := [][]string{
	[]string{"_", "_", "_"},
	[]string{"_", "_", "_"},
	[]string{"_", "_", "_"},
}

board[0][0] = "X"
board[2][2] = "O"
board[1][2] = "X"
board[1][0] = "O"
board[0][2] = "X"
```

#appending to slice - if cap of slice is too small then it will realloc and return that slice
```
var s []int

// append works on nil slices.
s = append(s, 0)

// The slice grows as needed.
s = append(s, 1)

// We can add more than one element at a time.
s = append(s, 2, 3, 4)
```
CONSOLE
```
len=0 cap=0 []
len=1 cap=2 [0]
len=2 cap=2 [0 1]
len=5 cap=8 [0 1 2 3 4]
```
#range of slice gives two returns per iteration
	-index
	-copy of the element at that index
```
var pow = []int{1, 2, 4, 8, 16, 32, 64, 128}
for i, v := range pow {
	fmt.Printf("index: %d Value:%d\n", i, v)
}
```
CONSOLE
```
index: 0 Value:1
index: 1 Value:2
index: 2 Value:4
...
```

#range syntax
	-You can skip the index or value by assigning to _
	-If you only want the index, you can omit the second variable
```
pow := make([]int, 10)
for i := range pow {
	pow[i] = i * 2
}
for _, value := range pow {
	fmt.Printf("%d\n", value)
}
```
CONSOLE
```
0
2
4
6
...
```

#maps - require make to set up for usage if going to be dynamic
```
type Vertex struct {
	Lat, Long float64
}

var m map[string]Vertex

func main() {
	m = make(map[string]Vertex)
	m["Bell Labs"] = Vertex{
		40.68433, -74.39967,
	}
	fmt.Println(m["Bell Labs"])
}
```
CONSOLE
```
[40.68433, -74.39967]
```

#map literals - like struct literals but require key
```
var m = map[string]Vertex{
	"Bell Labs": Vertex{
		40.68433, -74.39967,
	},
	"Google": Vertex{
		37.42202, -122.08408,
	},
}
//or
var m = map[string]Vertex{
	"Bell Labs": {40.68433, -74.39967},
	"Google":    {37.42202, -122.08408},
}
```
CONSOLE
```
[Bell Labs:{40.68433 -74.39967} Google:{37.42202 -122.08408}]
```

#mutating a map
```
m := make(map[string]int)

m["Answer"] = 42

m["Answer"] = 48

delete(m, "Answer")

v, ok := m["Answer"]
fmt.Println("The value:", v, "Present?", ok)
```
CONSOLE
```
The value: 42
The value: 48
The value: 0
The value: 0 Present? false
```

#map exercise
```
//count amount of times each word occurs in a string
import "strings"
func WordCount(s string) map[string]int {
	m := make(map[string]int)
	words := strings.Fields(s)
	
	for i := range words {
		m[words[i]] = m[words[i]] + 1
	}
	return m
}
```
