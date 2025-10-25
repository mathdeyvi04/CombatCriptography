all:
	g++ src/main.cpp -o m;

# Gerando Documentação
docs:
	@echo "\e[1;36m[INFO] Gerando HTML e LATEX com Doxygen\e[0m"
	@doxygen Doxyfile
	@echo "\e[1;36m[INFO] Compilando PDF na pasta docs/latex\e[0m"
	@$(MAKE) -C docs/latex
	@echo "\e[1;36m[INFO] Trazendo PDF para diretório padrão\e[0m"
	@mv docs/latex/refman.pdf Documentation.pdf