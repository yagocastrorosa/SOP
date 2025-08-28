# Módulos no Linux - Sistemas Operacionais

Implementação e correção de módulos do kernel Linux.

- **memory.c**: versão corrigida do módulo, que permite a cópia de 5 bytes.  
- **Módulos do Linux - Yago.pdf**: relatório curto (1–2 páginas) explicando a solução.

## Compilação e Teste do Módulo

Dentro do diretório com o arquivo `memory.c`:

```bash
make
sudo insmod memory.ko
echo -n "hello, MODULE" > /dev/memory
cat /dev/memory
```

É necessário criar o dispositivo caso ele não exista:
```bash
sudo mknod /dev/memory c 60 0
sudo chmod 666 /dev/memory
```

Por fim, é necessário descarregar e recompilar:
```bash
sudo rmmod memory.ko
make clean
make
```