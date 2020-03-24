# Code Style Check for kubernetes-client/c

## Parameter List of GNU Indent

### In command

```shell
indent -npro -nbad -nip -lp -npsl -npcs -i4 -ts4 -sob -br -ce -nut -bap -nbc -bbo -brs -cs -nfc1 -nfca -hnl -ip0 -nprs -saf -sai -saw -ci4 -cli0 -l200
```

### Detail Description

| Option | Description |
|:-------| :-----------|
|-npro   | Do not read ‘.indent.pro’ files.            |
|-nbad   | Do not force blank lines after declarations. |
|-nip    | Zero width indentation for parameters.           |
|-lp    | Line up continued lines at parentheses.            |
|-npsl   | Put the type of a procedure on the same line as its name.            |
|-npcs   | Do not put space after the function in function calls. |
|-i4     | Set indentation level to 4 spaces.           |
|-ts4    | Set tab size to 4 spaces.            |
|-sob    | Swallow optional blank lines.            |
|-br     | Put braces on line with if, etc.            |
|-ce     | Cuddle else and preceding ‘}’.            |
|-nut    | Use spaces instead of tabs. |
|-bap    | Force blank lines after procedure bodies.|
|-nbc    | Do not force newlines after commas in declarations.|
|-bbo    | Prefer to break long lines before boolean operators.|
|-brs    | Put braces on struct declaration line.|
|-cs     | Put a space after a cast operator.|
|-nfc1   | Do not format comments in the first column as normal.|
|-nfca   | Do not format any comments.|
|-hnl    | Prefer to break long lines at the position of newlines in the input.|
|-ip0    | Indent parameter types in old-style function definitions by 0 spaces.|
|-nprs   | Do not put a space after every '(' and before every ')'. |
|-saf    | Put a space after each for.   |
|-sai    | Put a space after each if. |
|-saw    | Put a space after each while. |
|-ci4    | Continuation indent of 4 spaces.|
|-cli0   | Case label indent of 0 spaces.|
|-l200   | Set maximum line length for non-comment lines to 200.|

## Reference

[GNU Indent Document](https://www.gnu.org/software/indent/manual/indent.html)
