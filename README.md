# GraphTheoryProject
This is the final project for Graph Theory Labolatories. The aim of the prohect was to implement Edmonds-Karp Algorithm, which is an implementation of the Ford–Fulkerson method for computing the maximum flow in a flow network.

## How it works ##
The programme reads data from given file and calculates maximum flow from source vertex to sink vertex. However it works correctly only if given file meets undermentioned conditions:

### 1. Proper file localization ###
To enable programme to read data from file the .txt file should be located in cmake-build-debug folder, where other test files are located.


![logo](https://github.com/PaulinaGacek/GraphTheoryProject/blob/main/File_localization.png "Proper file localization")


### 2. Correct syntax ###

File from which programme can correctly read data should be organised this way:

`n` - *number of vertices (int)*

`m` - *number of edges (int)*

`s` - *source wertex (int)*

`t` - *sink vertex (int)*

*m lines which represents egdes in the format:*
`a b c`

*where a - starting vertex, b - ending vertex, c - capacity*


Example of a file with correct syntax:

![logo](https://github.com/PaulinaGacek/GraphTheoryProject/blob/main/File_syntax_.png "Correct file syntax")
#### New line signs do not play any role in the correctness of syntax, because file is read sign-by-sign and not line-by-line. What really matters is that different numbers have to be separated by white sign. ####

###Problems which can be solved by this algorithm###
[ X ] calculating maximum flow in a flow network
[ X ] 

###Use of the algorithm ###
The Ford–Fulkerson method is widely used in solving allocation problems like those mentioned above, so the algorithm can be base for solvers. Additionally it is embraced in ruting

###*Sources:*###

1. *Agata SURÓWKA "ALGORYTM FORDA – FULKERSONA I JEGO ZNACZENIE W ROZWIĄZYWANIU PROBLEMÓW TRANSPORTOWYCH"*


Przeanalizuj powyższy algorytm: jakie problemy rozwiązuje, konkretne przykłady wykorzystania, z jakich metod korzysta się obecnie do rozwiązywania tych problemów (4pkt)

 PL: :arrow_heading_down:
 
 ### Problemy rozwiązywane przez algorytm: ###
 []
 
 ### Zastosowania algorytmu ###
 Algorytm Forda-Fulkersona jest szeroko używany do rozwiązywania problemów przydziału, więc może być on używany w implementacjach wielu solverów. Dodatkowo jest on wykożystywany w rutingu do optymalizacji wydajności sieci.
