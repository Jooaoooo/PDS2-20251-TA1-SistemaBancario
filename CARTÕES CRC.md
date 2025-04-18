<h2>CARTÕES CRC</h2>

- Realização de CARTÕES CRC para diferentes funcionalidades no Spectral Bank++.

### Cartão CRC 1: Cliente
| Classe       | Responsabilidades | Colaborações |
|--------------|------------------|--------------|
| **Cliente**  | - Autenticar usuário (login em duas etapas: senha e RG)<br>- Gerenciar dados pessoais<br>- Vincular-se a contas (PF/PJ) | - Conta (PF/PJ)<br>- Banco (validação de cadastro)<br>- Transação (operações) |

### Cartão CRC 2: Conta (Superclasse)
| Classe       | Responsabilidades | Colaborações |
|--------------|------------------|--------------|
| **Conta**    | - Gerenciar saldo básico<br>- Validar estado da conta<br>- Fornecer dados para extrato | - Cliente (titular)<br>- Transação (operações)<br>- Banco (atualização) |

### Cartão CRC 3: ContaPF (Subclasse)
| Classe       | Responsabilidades | Colaborações |
|--------------|------------------|--------------|
| **ContaPF**  | - Gerenciar saldo (poupança/corrente)<br>- Aplicar regras de PF<br>- Calcular rendimento tesouro | - Conta (herança)<br>- Investimento (vinculação)<br>- Transação (operações) |

### Cartão CRC 4: ContaPJ (Subclasse)
| Classe       | Responsabilidades | Colaborações |
|--------------|------------------|--------------|
| **ContaPJ**  | - Validar CNPJ e sócios<br>- Gerenciar limites corporativos<br>- Aplicar taxas específicas | - Conta (herança)<br>- Gerente (aprovação)<br>- Transação (operações) |

### Cartão CRC 5: Transação
| Classe       | Responsabilidades | Colaborações |
|--------------|------------------|--------------|
| **Transação** | - Registrar depósitos/saques/transferências<br>- Validar saldo suficiente<br>- Gerar comprovante | - Conta (origem/destino)<br>- Banco (autorização)<br>- PIX/Transferência |

### Cartão CRC 6: Banco
| Classe       | Responsabilidades | Colaborações |
|--------------|------------------|--------------|
| **Banco**    | - Gerenciar contas/clientes<br>- Validar transações globais<br>- Bloquear cartões<br>- Gerar relatórios | - Cliente (cadastro)<br>- Conta (gerenciamento)<br>- Transação (auditoria) |

### Cartão CRC 7: Empréstimo
| Classe       | Responsabilidades | Colaborações |
|--------------|------------------|--------------|
| **Empréstimo** | - Calcular juros e parcelas<br>- Validar score<br>- Liberar crédito<br>- Gerar contrato | - Cliente (solicitante)<br>- Banco (aprovação)<br>- Conta (depósito) |

### Cartão CRC 8: Gerente
| Classe       | Responsabilidades | Colaborações |
|--------------|------------------|--------------|
| **Gerente**  | - Aprovar contas PJ<br>- Auditar fraudes<br>- Gerar relatórios | - Banco (dados)<br>- ContaPJ (validação)<br>- Empréstimo (aprovações) |

### Cartão CRC 9: RelatórioGerencial
| Classe       | Responsabilidades | Colaborações |
|--------------|------------------|--------------|
| **RelatórioGerencial** | - Consolidar métricas mensais<br>- Filtrar por agência/período<br>- Gerar visualizações<br>- Alertar metas | - Banco (dados brutos)<br>- Gerente (personalização)<br>- Conta (detalhes) |