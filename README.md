<h1>SPECTRAL BANK++ - Sistema Bancário</h1>

<div align="center">
<img src="https://github.com/user-attachments/assets/5a1ca81a-85b5-4a4c-85e3-9b4f9f70cb0d"width="160px"/>
</div>
<h2>INTRODUÇÃO</h2>

**Introdução ao Projeto SPECTRAL BANK++**

O SPECTRAL BANK++ é um sistema bancário moderno e robusto, desenvolvido para oferecer uma experiência segura e eficiente aos seus usuários. Pode-se destacar o foco na gestão de contas, transações e clientes, o sistema elaborou-se para atender tanto pessoas físicas (com opções de conta poupança, corrente ou investimento) quanto pessoas jurídicas (com conta corrente), incluindo a possibilidade de contas conjuntas.  

Foram incorporadas funcionalidades bancárias essenciais, como depósitos (via PIX ou transferência), saques, pagamentos de contas, transferências entre contas, consultas de saldo e extratos detalhados, além de opções de empréstimo e investimento em títulos do tesouro nacional. Para garantir a segurança dos usuários, implementou-se um sistema de login em duas etapas, baseado em senha e RG.  

A persistência de dados é garantida por meio de arquivos `.txt`, onde as informações de contas e transações são armazenadas, permitindo recuperação e continuidade das operações. A interface gráfica será apresentada por meio do executável, demonstra um diferencial proporcionando uma experiência intuitiva e amigável, seguindo as melhores práticas de usabilidade.  

<h2>CONSTRUÇÃO</h2>

Dentre as ferramentas utilizadas para a construção do sistema foram implementadas técnicas de modelagem e orientação a objetos, de forma geral, optou-se pela linguagem c++ em função da segurança que pode ser alocada em atributos de classes. Inicialmente, o projeto buscou apresentar características centrais baseadas em TAD´s, Polimorfismo, Herança... Dessa forma, para apresentação de boas práticas de programação a separação dos blocos de código em blocos `.hpp` e `.cpp` foi realizada de forma a prezar pela execução do sistema e facilitação de implementação de testes unitários. Para a documentação optou-se pelo Doxygen em função da praticidade e relação com cartões CRC. A modelagem foi implementada de forma a ilustrar a utilização de user stories váriados com objetivo central em apresentação de funcionalidades uteis aos usuários do sistema. Buscou-se descrever a utilidade do mecanismo relacionado as funcionalidades apresendatas pelo sistema, o objetivo central nessa etapa se deu de forma a centrar o usuário a acessar o sistema, a ação a ser realizada por ele e  uma justificativa fim ou motivação.

<h2>USER STORIES</h2>

Acesse o link para verificação do USER STORIES no formato padrão exigido atualmente (C:\Users\joaoj\OneDrive\Documentos\UFMG\ELETRICA\Período 2\PDS2\PDS2-20251-TA1-SistemaBancario\USER STORIES.md).

- Apresentação de funcionalidades para funcionários externos ao sistema:

| **Usuário** |           **Ação**           |                          **Motivação**                         | **Criterios de aceitação**                                           |
|:-----------:|:----------------------------:|:--------------------------------------------------------------:|----------------------------------------------------------------------|
| Cliente     | Abertura de conta            | Para acessar os serviços do  banco e todas as funcionalidades  | Salvar dados em txt e valida unico RG                                |
| Cliente     | Depósito via PIX             | Quero aumentar o saldo em  conta para credito instrantâneo     | Valor depositado aparece como saldo e  é salvo no extrato            |
| Cliente     | Verificar extrato            | Verificar o extrato por  período para controle                 | Filtra o período do extrato e mostra  o saldo antes e após o período |
| Cliente     | Bloquear cartão              | O cartão foi perdido ou roubado,  para segurança é bloqueado   | Cartão exibido como bloqueado e  cliente impedido de usá-lo          |
| Cliente     | Investir em Tesouro Nacional | Utilizar o banco para investimento  para retorno em um período | Informa o retorno após o período  e o valor investido                |

- Apresentação de funcionalidades para usuários internos ao sistema:

| **Usuário** |      **Ação**      |                             **Motivação**                            | **Criterios de aceitação**                                                            |
|:-----------:|:------------------:|:--------------------------------------------------------------------:|---------------------------------------------------------------------------------------|
| Gerente     | Aprovar empréstimo | Disponibilizar crédito aos clientes  garantindo as normas do banco   | Verificar se cliente possui saldo  positivo e se possui conta,  mostrar saldo e conta |
| Gerente     | Cancelar contas    | Clientes com saldo nulo em vários meses  fogem a política da empresa | Mostrar saldo nulo e retirar cliente  do banco de dados                               |
| Gerente     | Gerar relatório    | Verificar todos os clientes ativos  e o saldo em conta de cada       | Mostrar relatório de contas cadastradas  e relatório de saldo de cada conta           |

<h2>CONTRIBUINTES</h2>

_João Augusto Rosa Cunha_ <br>
_Lucas Miller dos Santos Sousa_<br>
_Alan Pessoa Silva_<br>
_Natan Inoue dos Reis_
