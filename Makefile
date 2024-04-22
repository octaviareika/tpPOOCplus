# Makefile para compilar os arquivos C++ em pontoC

# Comandos e opções de compilação
CXX = g++
CXXFLAGS = -std=c++11 -Wall
INCLUDES = -IpontoH

# Diretórios dos arquivos
SRCDIR = pontoC
HDRDIR = pontoH
BUILDDIR = build
TARGET = programa

# Listar todos os arquivos .cpp
SRCS := $(wildcard $(SRCDIR)/*.cpp)
OBJS := $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SRCS))

# Nome dos headers
DEPS := $(wildcard $(HDRDIR)/*.hpp)

# Comando padrão (gerar o executável)
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ $^

# Compilar cada arquivo .cpp em um arquivo .o
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp $(DEPS)
	@mkdir -p $(BUILDDIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $<

# Limpar arquivos temporários e o executável
clean:
	rm -rf $(BUILDDIR) $(TARGET)

.PHONY: all clean
