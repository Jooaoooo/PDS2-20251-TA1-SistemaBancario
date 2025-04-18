<h2>USER STORIES</h2>
 
- Realização do histórico de usuário para diferentes funcionalidades no Spectral Bank++.

<h3>Cadastro de Cliente</h3>
Como um novo cliente,
eu quero criar uma conta no banco fornecendo meus dados pessoais (nome, RG, senha, etc.),
para que eu possa acessar os serviços bancários com segurança.

<h4>Critérios de aceitação</h4>
1. Sistema valida RG como único e senha com mínimo de 6 caracteres.<br>
2. Dados são salvos em arquivo .txt após confirmação.<br>

<h3>Depósito via PIX</h3>
Como um cliente,
eu quero realizar um depósito em minha conta usando PIX,
para que o valor seja creditado instantaneamente sem taxas adicionais.

<h4>Critérios de aceitação</h4>
1. Valor depositado aparece no saldo imediatamente.<br>
2. Transação registrada no extrato com horário e chave PIX usada.<br>

<h3>Verificar Extrato</h3>
Como um cliente,
eu quero visualizar meu extrato bancário filtrando por datas (ex.: "últimos 30 dias"),
para que eu possa acompanhar meus gastos e recebimentos de forma organizada.

<h4>Critérios de aceitação</h4>
1. Extrato exibe transações filtradas por período selecionado.<br>
2. Saldo anterior e posterior à data consultada é exibido.<br>

<h3>Bloquear Cartão</h3>
Como cliente, eu quero bloquear meu cartão temporariamente pelo executável fornecido pelo banco, 
para que eu possa evitar fraudes em caso de perda ou roubo.

<h4>Critérios de aceitação</h4>
1. Cartão é desativado temporariamente no sistema após confirmação.<br>
2. Notificação é enviada ao cliente confirmando o bloqueio.<br>

<h3>Investir em Tesouro Nacional</h3>
Como um cliente,
eu quero investir em títulos do tesouro direto pelo banco,
para que eu possa ver projeções de retorno após um determinado período (ex.: 12 meses).

<h4>Critérios de aceitação</h4>
1. O sistema deve calcular e exibir uma projeção de retorno bruto (valor futuro) com base no valor investido, 
tipo de título e prazo selecionado. - Testar com valores conhecidos (ex.: R$1.000 em Tesouro Selic 2026) 
e comparar com a calculadora oficial do Tesouro Direto.<br>
2. O investimento só deve ser confirmado após a exibição de um termo de riscos 
e a confirmação explícita do cliente (duplo clique ou checkbox).<br>

<h3>Aprovar Empréstimo</h3>
Como gerente, eu quero aprovar ou rejeitar solicitações de empréstimo, 
para que eu garanta que os critérios do banco sejam atendidos.

<h4>Critérios de aceitação</h4>
1. Empréstimo só é liberado após análise de score de crédito.<br>
2. Contrato digital é gerado e assinado eletronicamente.<br>

<h3>Cancelar Contas</h3>
Como gerente, eu quero cancelar contas de clientes com atividades suspeitas ou inativas, 
para que eu minimize riscos de fraude ou inatividade.

<h4>Critérios de aceitação</h4>
1. Sistema registra motivo do cancelamento (ex.: fraude/inatividade por período). <br>
2. Cliente recebe mensagem com justificativa e procedimentos.<br>

<h3>Gerar Relatórios</h3>
Como gerente, eu quero gerar relatórios mensais de transações (depósitos, saques, transferências, 
cadastro de clientes, saídas), para que eu envie dados à diretoria.

<h4>Critérios de aceitação</h4>
1. O relatório deve segmentar transações por tipo (depósito, saque, transferência) e mostrar totais por categoria.<br>
2. O sistema deve permitir filtrar relatórios por cliente específico, quando aplicável.<br>