.PHONY: clean All

All:
	@echo "----------Building project:[ Progettino - Debug ]----------"
	@cd "Progetto" && "$(MAKE)" -f  "Progettino.mk"
clean:
	@echo "----------Cleaning project:[ Progettino - Debug ]----------"
	@cd "Progetto" && "$(MAKE)" -f  "Progettino.mk" clean
