#  Exercício 1: Criar função printHeader

Utilize seus conhecimentos para criar uma função denominada printHeader que gera e imprime
na saída padrão o cabeçalho de uma tabela. Os rótulos de cada coluna do cabeçalho devem ser
especificados no próprio programa (i.e. hard-coded) através de um vetor de strings. Confira abaixo
o esqueleto geral do programa:

```
1 #include < iostream >
2 #include < iomanip >
3 #include < vector >
4 using namespace std ;
5
6 /* *!
7 * Print the table’s header to the terminal ( std :: cout ).
8 * @param fields_ Reference to the list of header fields to be printed .
9 */
10 void printHeader ( const std :: vector < std :: string > & fields_ ) {
11 // TODO
12 }
13
14 int main () {
15 std :: vector < std :: string > fieldNames = { " ITEM ", " QUANTIDADE ", " VALOR UNITARIO " };
16 printHeader ( fieldNames ); // Imprimir cabecalho da tabela .
17 return EXIT_SUCCESS ;
18 }
```

Cada campo deve ser delimitado por linhas verticais ‘|’ e conter um espaço em branco de cada
lado. Em resumo, o cabeçalho deve ser gerado automaticamente por meio de laços e dos comandos
de manipulação de fluxo de maneira a produzir a seguinte saída:

```
+------+------------+----------------+
| ITEM | QUANTIDADE | VALOR UNITARIO |
+------+------------+----------------+
```

<b>Importante</b>: Seu código deve ser desenvolvido de tal maneira que se for necessário acrescentar
um campo extra no cabeçalho da tabela, bastaria incluir o novo nome em fieldNames , sem ser
necessário alterar a função ``printHeader``.


