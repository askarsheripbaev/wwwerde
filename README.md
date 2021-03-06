[![Work in Repl.it](https://classroom.github.com/assets/work-in-replit-14baed9a392b3a25080506f3b7b6d57f295ec2978f6f33ec97e36a161684cbe9.svg)](https://classroom.github.com/online_ide?assignment_repo_id=4083398&assignment_repo_type=AssignmentRepo)
# Сколько раз встречается каждое слово без учёта регистра?
Ваша задача - реализовать функцию
```c++
auto count_words(std::string const &input) -> std::map<std::string, int>
```
которая считает, сколько раз встречается каждое слово в строке без учёта регистра. Важное замечание: ключом в выходном словаре должны быть слова в одном из тех написаний, в котором они встречаются в строке. Например, для входа "Зомби зомби зомби!" допустимы два выхода: или `{"Зомби", 3}`, или `{"зомби", 3}`, но не `{"ЗОМБИ", 3}`.
