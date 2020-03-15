# Exercício 3: Construir `getInteger()`

Normalmente a leitura de um tipo formato a partir do terminal é realizado com `std::cin`. Contudo,
você já aprendeu que este tipo de entrada não é robusto o suficiente para lidar com entradas com
erros fornecida pelos usúarios.
Por exemplo, se tentarmos ler uma variável inteira `val` com `std::cin`:

``` 
int val;
std::cin >> val;
```

e o usuário digitar, por engano, 12t no lugar do valor 126, a variável val armazenará o valor
incorreto 12.

Desenvolva uma função denominada `int getInteger(string msg_)` que apresenta uma mensagem `msg_` na tela solicitando um inteiro, recebe o inteiro e o retorna para o <b>código cliente</b>. A
função deve ficar em laço solicitando um valor até que o usuário forneça um valor inteiro correto.

Na sua solução lembre de usar os métodos como `fail`, `eof`, a função `getline` e a nova
classe `istringstream`. A estratégia sugerida é usar `getline` com o `std::cin`, associar a string
lida com um fluxo de string para então converter a string em inteiro e o retornar para o cliente.

Veja, abaixo, um exemplo de uso da função `getInteger` do ponto de vista do código cliente

```
auto val = getInteger( "Forneca um inteiro : " );
```
