# Markdown-to-cpp parser

## Overview 

This repository contains my programming notes, originally written in Markdown format. However, since this repository primarily focuses on C++ programming, I convert these Markdown files into C++ source files. This ensures that GitHub correctly classifies the repository as a C++ project.

## Conversion Format

The original notes are written in the following Markdown format:

```markdown 
# Title

## Method
\```cpp==
<cpp program>
\```
```

After conversion, they are rewritten into C++ files using the following structure:

```cpp
/*
    Title
*/
#include<bits/stdc++.h>
using namespace std;

<cpp program>
```