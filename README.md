#Analizador Léxico e Sintático sem Retrocessos

Trabalho de Linguagem Formais 2018/2
Ciências da Computação
UCS - CARVI
Professor Ricardo Vargas Dorneles

Descrição do trabalho

Implemar um Analizador Lexico e Sintatico para a linguagem C, que reconhece os comando:
1. Comando while.
2. Comando do-while.
3. Comando for.
4. Comando if.
5. Atribuição. É um operador, podendo aparecer em expressões.
6. Comando switch-case. Com a possibilidade da entrada ‘default’.
7. Expressões: Com a lista completa de operadores em C.
8. Blocos de comandos: grupos de comandos agrupados com chaves.
9. Declarações e chamadas de Funções

Gramaticas geradas estão comentadas em cada uma de suas respectivas funções. Sendo o codigo gerado pelo ParsingEDU (Desenvolvido por Diogo Manica, UCS).

Analizador Sintatico foi desenvolvido sem retrocessos.

#Funcionamento

É necessário criar um arquivo **entrada.cpp** que conterá o código há ser analizádo. O arquivo entrada.cpp deve está no mesmo diretório onde está o Analizador.exe.

Analizador Léxico gera o arquivo **Saida.lex** que conté: Token, Lexema, Linha e Coluna.

