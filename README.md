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


### Problems which can be solved by this algorithm ###
[ X ] maximum flow problem
[ X ] minimum cut problem
[ X ] transshipment problem
[ X ] assignment problem


### Use of the algorithm ###
The Ford–Fulkerson method is widely used in solving allocation problems like those mentioned above, so the algorithm can be base for solvers. Additionally it is embraced in solving problems which can be represented with flow networks - telecomunication, transport, ruting.
Moreover this model of computation still has applications throughout the spectrum of computer science, such as Airline Scheduling, Bipartite Matching, Survey Design, and Image Segmentation. 

### *Sources:* ###

1. *Agata SURÓWKA "ALGORYTM FORDA – FULKERSONA I JEGO ZNACZENIE W ROZWIĄZYWANIU PROBLEMÓW TRANSPORTOWYCH"*
2. *Sabhya Chhabria "Real-World Network Flow — “Cricket Elimination Problem” "*


Przeanalizuj powyższy algorytm: jakie problemy rozwiązuje, konkretne przykłady wykorzystania, z jakich metod korzysta się obecnie do rozwiązywania tych problemów (4pkt)
Są szybsze algorytmy opartę o metodę Ford: algorytm Dinica oraz Malhotry, Kumara i Maheshwariego.

 PL: :arrow_heading_down:
 
 ### Problemy rozwiązywane przez algorytm: ###
 - [X] problem maksymalnego przepływu
 - [ X ] problem minimalnego cięcia
 [ X ] problem transportowy
 [ X ] problem przyporządkowania
 
 ### Zastosowania algorytmu ###
 Algorytm Forda-Fulkersona jest szeroko używany do rozwiązywania problemów przydziału, więc może być on używany w implementacjach wielu solverów. Dodatkowo jest on wykorzystywany w rozwiązywaniu problemów związanych z sieciami przepływowymi - w telekomunikacji, transporcie i np. rutingu do optymalizacji wydajności sieci. Co więcej ten model obliczeniowy w dalszym ciągu jest stosowany w planowaniu harmonogramu lotów, znajdowania maksymalnych skojarzeń w grafach dwudzielnych oraz podczas segmentacji obrazów.
