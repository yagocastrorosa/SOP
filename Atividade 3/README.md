# Programação Concorrente - Sistemas Operacionais

Implementações em **C++ com pthreads** para resolução de problemas utilizando primitivas de sincronização.  
- **questao_1.cpp**: verificação de número perfeito com múltiplas threads.  
- **questao_2.cpp**: contagem de frequência de palavras em texto usando threads.  

## Compilação
```bash
g++ questao_1.cpp -o questao_1 -lpthread
g++ questao_2.cpp -o questao_2 -lpthread
```

## Execução
```bash
./questao_1 N P
./questao_2 entrada.txt
```