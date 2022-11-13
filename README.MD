# MTFIND

mtfind can find all substrings that match with mask

## Build
```shell
mkdir -p build && cd build
cmake ..
cmake --build .
```

## Run
Base run configuration: `mtfind path_to_file "mask"`

Run example
```shell
mtfind input.txt "?ad"
```

Content of `input.txt`
```text
I've paid my dues
Time after time.
I've done my sentence
But committed no crime.
And bad mistakes ?
I've made a few.
I've had my share of sand kicked in my face
But I've come through.
```

Output:
```text
3
5 5 bad
6 6 mad
7 6 had
```
3 - number of substrings found  
`5 5 bad` - first `5` is number of string at source file, next `5` is start position of substring,
and `bad` is our found substring