import sys

def main():
    # Проверка аргументов командной строки (для совместимости с C++)
    if len(sys.argv) > 1:
        try:
            n = int(sys.argv[1])
            m = int(sys.argv[2])
        except ValueError:
            print("Ошибка: введите целые числа.")
            return
    else:
        try:
            n = int(input("Введите количество строк (N): "))
            m = int(input("Введите количество столбцов (M): "))
        except ValueError:
            print("Ошибка: введите целые числа.")
            return

    if n <= 0 or m <= 0:
        print("Размеры таблицы должны быть положительными.")
        return

    # Определяем ширину столбца для выравнивания
    # Самое большое число n * m  но столбцов M поэтому смотрим на max(n*i)
    max_val = n * m
    col_width = len(str(max_val)) + 1  # +1 для отступа

    print("\nТаблица умножения:")
    # Заголовок столбцов
    print(" " * (col_width - 1), end="")
    for j in range(1, m + 1):
        print(f"{j:>{col_width}}", end="")
    print()
    
    # Разделитель
    print("-" * (col_width * (m + 1)))

    for i in range(1, n + 1):
        # Заголовок строки
        print(f"{i:<{col_width - 1}}|", end="")
        for j in range(1, m + 1):
            print(f"{i * j:{col_width}}", end="")
        print()

if __name__ == "__main__":
    main()