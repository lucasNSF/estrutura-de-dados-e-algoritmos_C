<h1 align="center">Estrutura de Dados e Algoritmos</h1>

<p align="justify">Este repositório foi feito com a finalidade de compartilhar um pouco do meu conhecimento sobre o estudo de Estruturas de Dados e Algoritmos, no qual estou aprendendo na minha faculdade. O conteúdo estará divido em pastas de maneira organizada, cada uma contendo seu próprio README para facilitar o estudo e possíveis consultas futuras. Espero que esse conhecimento possa ajudar de alguma forma a você que caiu aqui de paraquedas! 😄</p>

<div align="center" style>
  <h3>Linguagem Utilizada:</h2>
  <img height="40px" width="40px" src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/c/c-original.svg" />
</div>

## Conceitos Básicos 🤔

### O que é um Algoritmo?
- Uma sequência finita de instruções lógicas que resolvem uma determinada tarefa.

### O que é uma Estrutura de Dados?
- Modo de armazenamento e organização de dados em um computador, de modo que eles possam ser utilizados de forma eficiente.

### Estrutura de Dados x Algoritmos
- <p align="justify">Estamos sempre lidando com algoritmos, principalmente no universo da programação. Utilizamos algoritmos para manipular dados e, quando organizamos esses dados tornando nossas operações com eles mais eficientes e coerentes, temos uma <strong>estrutura de dados</strong>.</p>

## Análise de Algoritmos 📈

<p align="justify">A análise de algoritmos tornou-se essencial. A comparação de um determinado algoritmo com outro é importante para tirarmos conclusões de ambos e, dessa forma, escolhermos o algoritmo mais eficiente para uma determinada situação.</p>

Os tipos de dados que podem ser utilizados para analisar um algoritmo são:
- **Dados Reais**: Entregam a verdadeira medida do tempo de execução.
- **Dados Aleatórios**: Assegura que as experiências testam o algoritmo e não apenas os dados específicos. Representa situação de caso **médio**.
- **Dados Perversos**: Mostram que o algoritmo funciona com qualquer tipo de dado. Representa a situação de **pior** caso.
- **Dados Benéficos**: Mostram que o seu algoritmo funciona apenas com os tipos de dados esperados. Representa a situação de **melhor** caso.

Realizar uma análise **precisa** de um algoritmo é uma tarefa complicada pois são considerados muitos fatores, tais como:
- A linguagem em que determinado algoritmo é implementado.
- O hardware da máquina em que o programa será executado.
- É difícil prever tempos de execução de cada instrução e antever otimizações.
- Muitos algoritmos não são bem compreendidos.

<p align="justify">Entretanto, ainda é feita a análise de algoritmos a partir de modelos matemáticos simples, que ignoram o hardware e o software escolhidos para executar o programa, e nos trazem uma previsão do tempo de execução do algoritmo.</p>

<p align="justify">Para melhor ilustrar essa situação, imagine 5 algoritmos diferentes feitos para realizar um mesmo tipo de situação (A1, A2, A3, A4 e A5). Podemos calcular a eficiência de cada um desses algoritmos a partir de uma função que calcula o número de operações que um determinado algoritmo efetua para <strong>N</strong> entradas. Essa função é chamada <em>Tĸ(n)</em>.</p>

<p align="justify">Em que <em>T</em> significa o Tempo de Execução do Algoritmo. <em>k</em> é a variável que indica qual é o algoritmo (A1, A2, A3, A4 ou A5) e o <em>n</em> indica a quantidade de entradas.</p>

A imagem abaixo ilustra o funcionamento desses algoritmos:

**OBS** - Considere que cada operação leva 1ms para ser efetuada.

<div align="center"><img align="center" src="assets/images/mainReadMe.png" alt="Ilustração do Funcionamento dos Algoritmos"></div>
<br>
<p align="justify">Note que para um tamanho de entrada igual a 512 (n = 512), para resolver um mesmo tipo de problema, existem algoritmos que demoram 10¹³ séculos para terminar a execução (algoritmo A5) e outros que demorariam 0.512s para completá-la (algoritmo A1). Perceber essa diferença só foi possível analisando os algoritmos, e assim, podemos escolher o melhor deles para resolver uma determinada situação.</p>

<p align="justify">Repare também que, na mesma tabela, logo abaixo das letras dos algoritmos, temos algumas funções como <strong>n</strong>, <strong>nlog n</strong>, <strong>n²</strong>, <strong>n³</strong> e <strong>2^n</strong>. Essas funções representam a Complexidade de cada um desses algoritmos, estudaremos ela logo em seguida!</p>