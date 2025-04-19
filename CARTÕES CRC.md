<h2>CARTÕES CRC</h2>

- Realização de CARTÕES CRC para diferentes funcionalidades no Spectral Bank++.

### Cartão CRC 1: Cliente
| Classe       | Responsabilidades | Colaborações |
|--------------|------------------|--------------|
| **Cliente**  | 1. Autenticar usuário (login em duas etapas: senha e RG)<br>2. Gerenciar dados pessoais (nome, endereço, RG)<br>3. Vincular-se a contas (PF/PJ)<br>4. Solicitar bloqueio/desbloqueio de cartão<br>5. Acessar histórico de transações<br>6. Atualizar métodos de contato (e-mail, telefone) | - Conta (PF/PJ)<br>- Banco (validação)<br>- Transação<br>- Cartão |

### Cartão CRC 2: Conta (Superclasse)
| Classe       | Responsabilidades | Colaborações |
|--------------|------------------|--------------|
| **Conta**    | 1. Gerenciar saldo básico<br>2. Validar estado da conta (ativa/bloqueada)<br>3. Fornecer dados para extrato<br>4. Aplicar tarifas mensais<br>5. Gerar número da conta único<br>6. Validar titularidade (PF/PJ) | - Cliente<br>- Transação<br>- Banco<br>- Extrato |

### Cartão CRC 3: ContaPF (Subclasse)
| Classe       | Responsabilidades | Colaborações |
|--------------|------------------|--------------|
| **ContaPF**  | 1. Gerenciar saldo (poupança/corrente)<br>2. Aplicar regras de PF (limites de saque)<br>3. Calcular rendimento tesouro direto<br>4. Validar CPF do titular<br>5. Gerenciar conta conjunta (se aplicável) | - Conta<br>- Investimento<br>- Transação<br>- Cliente |

### Cartão CRC 4: ContaPJ (Subclasse)
| Classe       | Responsabilidades | Colaborações |
|--------------|------------------|--------------|
| **ContaPJ**  | 1. Validar CNPJ e sócios<br>2. Gerenciar limites corporativos<br>3. Aplicar taxas específicas (TED/DOC)<br>4. Emitir cobranças (boletos)<br>5. Integrar com sistemas contábeis | - Conta<br>- Gerente<br>- Transação<br>- Banco |

### Cartão CRC 5: Transação
| Classe       | Responsabilidades | Colaborações |
|--------------|------------------|--------------|
| **Transação** | 1. Registrar depósitos/saques/transferências<br>2. Validar saldo suficiente<br>3. Gerar comprovante<br>4. Converter moedas (se internacional)<br>5. Rastrear status (pendente/concluída) | - Conta<br>- Banco<br>- PIX<br>- Cartão |

### Cartão CRC 6: Banco
| Classe       | Responsabilidades | Colaborações |
|--------------|------------------|--------------|
| **Banco**    | 1. Gerenciar contas/clientes<br>2. Validar transações globais<br>3. Bloquear cartões (fraude/perda)<br>4. Gerar relatórios mensais<br>5. Processar folha de pagamento (PJ)<br> | - Cliente<br>- Conta<br>- Transação<br>- Gerente |

### Cartão CRC 7: Empréstimo
| Classe       | Responsabilidades | Colaborações |
|--------------|------------------|--------------|
| **Empréstimo** | 1. Calcular juros e parcelas<br>2. Validar score (Serasa/SPC)<br>3. Liberar crédito (fundos SPECTRAL)<br>4. Gerar contrato digital<br>5. Notificar vencimentos<br>6. Renegociar dívidas | - Cliente<br>- Banco<br>- Conta<br>- Gerente |

### Cartão CRC 8: Gerente
| Classe       | Responsabilidades | Colaborações |
|--------------|------------------|--------------|
| **Gerente**  | 1. Aprovar contas PJ<br>2. Auditar transações suspeitas<br>3. Liberar limites especiais (VIP)<br>4. Gerar relatórios customizados<br>5. Gerenciar equipe de atendimento<br>6. Aprovar renegociações | - Banco<br>- ContaPJ<br>- Empréstimo<br>- RelatórioGerencial |

### Cartão CRC 9: RelatórioGerencial
| Classe       | Responsabilidades | Colaborações |
|--------------|------------------|--------------|
| **RelatórioGerencial** | 1. Consolidar métricas mensais<br>2. Filtrar por agência/período<br>3. Gerar dashboards interativos<br>4. Alertar metas não atingidas<br>5. Exportar em PDF/Excel<br> | - Banco<br>- Gerente<br>- Conta<br>- Transação |