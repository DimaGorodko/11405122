def isValid(s: str) -> bool:
    # Словарь для хранения пар скобок
    bracket_map = {')': '(', '}': '{', ']': '['}
    stack = []

    for char in s:
        if char in bracket_map.values():  # Если это открывающая скобка
            stack.append(char)
        elif char in bracket_map.keys():  # Если это закрывающая скобка
            if not stack or stack[-1] != bracket_map[char]:
                return False
            stack.pop()  # Извлекаем соответствующую открывающую скобку

    return not stack  # Если стек пуст, все скобки были сопоставлены

# Пример использования
print(isValid("()"))      # Вывод: True
print(isValid("(]"))      # Вывод: False
print(isValid("{[]}"))    # Вывод: True
print(isValid("([)]"))    # Вывод: False
print(isValid("{[()]}"))  # Вывод: True
