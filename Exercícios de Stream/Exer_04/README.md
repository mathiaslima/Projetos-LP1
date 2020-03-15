# Exercício 4: Tabela Suprema!

No exercício final você deve criar um programa que segue o seguinte roteiro.

1. Usar argumentos de linha de comando (i.e. `argc` e `argv` ) para receber dois nomes de arquivos
de entrada.
2. Ler o primeiro arquivo que contém uma lista de <i>n</i> rótulos, <i>r1, r2, . . . , rn,</i> para compor o
cabeçalho de uma tabela, um rótulo por linha, e armazenar em um `vector` ;
3. Ler o segundo arquivo de inteiros que deve conter <i>m</i> linhas, cada um com <i>n</i> inteiros e os
armazenar em um `vector`. Cada um dos inteiros de uma linha corresponde a um valor
associado a um dos rótulos.
4. Produzir uma tabela com cabeçalho no estilo do Exercício 2 e imprimir o cabe¸calho, simultaneamente, no terminal e em um arquivo de saída de sua escolha.
5. Imprimir, simultaneamente, no terminal e no mesmo arquivo de saída, o corpo da tabela de
acordo com os dados lidos, de maneira que os inteiros fiquem alinhados com seus respectivos
rótulos

Veja um exemplo de um arquivo de entrada de rótulos:
```
ITEM
QUANTIDADE
VALOR UNITARIO
```

Abaixo temos um exemplo de um arquivo de entrada de dados da tabela:

```
23 123 985
653 3 5
45 0 1
67 18 15
123 204 10
78 856 234
873 777 7612
554 354 5131
21 132 132
```

Por fim, confira um exemplo de um arquivo de saída gerado corretamente, de acordo com as
entradas-exemplo:

```
+------+------------+----------------+
| ITEM | QUANTIDADE | VALOR UNITARIO |
+------+------------+----------------+
|    23|         123|             985|
|   653|           3|               5|
|    45|           0|               1|
|    67|          18|              15|
|   123|         204|              10|
|    78|         856|             234|
|   873|         777|            7612|
|   554|         354|            5131|
|    21|         132|             132|
+------+------------+----------------+
````
