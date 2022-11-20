.PHONY: clean All

All:
	@echo "----------Building project:[ Progetto - Debug ]----------"
	@cd "Progetto" && "$(MAKE)" -f  "Progetto.mk"
clean:
	@echo "----------Cleaning project:[ Progetto - Debug ]----------"
	@cd "Progetto" && "$(MAKE)" -f  "Progetto.mk" clean
