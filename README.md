# Markov Chain text generator in C++.

This program will process a text file and map it to a markov chain,
where each state is a word and it's next state is just the next word that
could follow it. It has built in probability by just adding duplicate next 
words to the edges vector. This means if word `a` follows word `b` twice, it
will appear twice in the list of possible next words.

## Example Output:
this is using the above text:

#### generated sentence
```
next state is a follows word that could follow it. it will appear twice in the list
of possible next words. twice, it has built in the edges vector. this program will
process a text file and it's next word a word that could follow it. it has built in
```
#### The generated structure:
```
    word    edges
[0] this: [program, means, ]
[1] program: [will, ]
[2] will: [process, appear, ]
[3] process: [a, ]
[4] a: [text, markov, word, follows, ]
[5] text: [file, ]
[6] file: [and, ]
[7] and: [map, it's, ]
[8] map: [it, ]
[9] it: [to, has, will, ]
[10] to: [a, the, ]
[11] markov: [chain,, ]
[12] chain,: [where, ]
[13] where: [each, ]
[14] each: [state, ]
[15] state: [is, is, ]
[16] is: [a, just, ]
[17] word: [and, that, a, b, ]
[18] it's: [next, ]
[19] next: [state, word, words, words., ]
[20] just: [the, adding, ]
[21] the: [next, edges, list, ]
[22] that: [could, ]
[23] could: [follow, ]
[24] follow: [it., ]
[25] it.: [it, ]
[26] has: [built, ]
[27] built: [in, ]
[28] in: [probability, the, ]
[29] probability: [by, ]
[30] by: [just, ]
[31] adding: [duplicate, ]
[32] duplicate: [next, ]
[33] words: [to, ]
[34] edges: [vector., ]
[35] vector.: [this, ]
[36] means: [if, ]
[37] if: [word, ]
[38] follows: [word, ]
[39] b: [twice,, ]
[40] twice,: [it, ]
[41] appear: [twice, ]
[42] twice: [in, ]
[43] list: [of, ]
[44] of: [possible, ]
[45] possible: [next, ]
[46] words.: []
```


## Building

```bash
mkdir build
cmake -B build -S src
cd build
cmake --build .
./markov_text_gen <file>
```
