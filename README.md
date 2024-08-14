# `rpn` - simple command-line RPN calculator

`rpn` is a [Reverse Polish Notation](https://en.wikipedia.org/wiki/Reverse_Polish_notation) calculator that can be used in the terminal. Many mathematical operations are supported in this calculator; see below for a list.

## Using `rpn`

| **Operation** | **Supported Operators** | **Example and Result** |
| --- | --- | -- |
| Addition | `+` or `add` | `rpn 3 2 +` yields `5` |
| Subtraction | `-` or `subtract` | `rpn 3 2 -` yields `1` |
| Multiplication[^1] | `*` or `multiply` | `rpn 3 2 multiply` yields `6` |
| Division | `/` or `divide` | `rpn 3 2 divide` yields `1.5` |
| Exponentiation | `^` or `pow` | `rpn 3 2 ^` yields `9` |
| Square root | `sqrt` | `rpn 9 sqrt` yields `3` |
| Cube root | `cbrt` | `rpn 27 cbrt` yields `3` |
| *n*th root | `root` | `rpn 27 3 root` yields `3` |
| Percent | `%` or `percent` | `rpn 100 %` yields `1` |
| Sine | `sin` or `sine` | `rpn 0 sin` yields `0` |
| Cosine | `cos` or `cosine` | `rpn 0 cos` yields `1` |
| Tangent | `tan` or `tangent` | `rpn 0 tan` yields `0` |
| Arcsine | `asin` or `arcsin` or `arcsine` | `rpn 0 arcsin` yields `0` |
| Arccosine | `acos` or `arccos` or `arccosine` | `rpn 1 arccos` yields `0` |
| Arctangent | `atan` or `arctan` or `arctangent` | `rpn 0 arctan` yields `0` |

[^1]: The `*` character may need to be escaped on the terminal due to its use as a wildcard character; for example, you may need to type `rpn 3 2 '*'`.

Additionally, the following are interpreted as numbers:
| **Input** | **Description** |
| --- | --- |
| Any string of characters 0-9 | The specified number |
| `e` | The constant [$e$](https://en.wikipedia.org/wiki/E_(mathematical_constant)); that is, about $2.71828$ |
| `pi` | The constant [$\pi$](https://en.wikipedia.org/wiki/Pi); that is, about $3.14159$ |