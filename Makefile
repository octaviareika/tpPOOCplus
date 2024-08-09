# Variáveis
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
SRCDIR = pontoC
TARGET = programa

# Coleta todos os arquivos .cpp no diretório pontoC
SOURCES = $(wildcard $(SRCDIR)/*.cpp)

# Substitui a extensão .cpp por .o para criar uma lista de arquivos-objeto
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=%.o)

# Regras principais
all: $(TARGET)

# Regra para compilar o programa
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

# Regra para compilar cada arquivo .cpp em um arquivo .o
%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


# Limpeza completa, incluindo binários
clean-all: clean
	rm -f $(TARGET)
