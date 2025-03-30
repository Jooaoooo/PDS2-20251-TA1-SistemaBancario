<h1>SPECTRAL BANK++ - Sistema Bancário</h1>

<div align="center">
<img src="https://github.com/user-attachments/assets/5a1ca81a-85b5-4a4c-85e3-9b4f9f70cb0d"width="160px"/>
</div>
<h2>INTRODUÇÃO</h2>

**Introdução ao Projeto SPECTRAL BANK++**

O SPECTRAL BANK++ é um sistema bancário moderno e robusto, desenvolvido para oferecer uma experiência segura e eficiente aos seus usuários. Pode-se destacar o foco na gestão de contas, transações e clientes, o sistema elaborou-se para atender tanto pessoas físicas (com opções de conta poupança, corrente ou investimento) quanto pessoas jurídicas (com conta corrente), incluindo a possibilidade de contas conjuntas.  

Foram incorporadas funcionalidades bancárias essenciais, como depósitos (via PIX ou transferência), saques, pagamentos de contas, transferências entre contas, consultas de saldo e extratos detalhados, além de opções de empréstimo e investimento em títulos do tesouro nacional. Para garantir a segurança dos usuários, implementou-se um sistema de login em duas etapas, baseado em senha e RG.  

A persistência de dados é garantida por meio de arquivos `.txt`, onde as informações de contas e transações são armazenadas, permitindo recuperação e continuidade das operações. A interface gráfica, desenvolvida com `gtkmm`, demonstra um diferencial proporcionando uma experiência intuitiva e amigável, seguindo as melhores práticas de usabilidade.  

<h2>CONSTRUÇÃO</h2>

Dentre as ferramentas utilizadas para a construção do sistema foram implementadas técnicas de modelagem e orientação a objetos, de forma geral, optou-se pela linguagem c++ em função da segurança que pode ser alocada em atributos de classes. Inicialmente, o projeto buscou apresentar características centrais baseadas em TAD´s, Polimorfismo, Herança... Dessa forma, para apresentação de boas práticas de programação a separação dos blocos de código em blocos `.hpp` e `.cpp` foi realizada de forma a prezar pela execução do sistema e facilitação de implementação de testes unitários. Para a documentação optou-se pelo Doxygen em função da praticidade e relação com cartões CRC. A modelagem foi implementada de forma a ilustrar a utilização de user stories váriados com objetivo central em apresentação de funcionalidades uteis aos usuários do sistema. Buscou-se descrever a utilidade do mecanismo relacionado as funcionalidades apresendatas pelo sistema, o objetivo central nessa etapa se deu de forma a centrar o usuário a acessar o sistema, a ação a ser realizada por ele e  uma justificativa fim ou motivação.

<h2>USER STORIES</h2>

