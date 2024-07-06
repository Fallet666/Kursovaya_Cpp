**Курсовая работа по C++. Работа инженерного калькулятора через сложные структуры ООП, сигналы и обработчики.**

Надо моделировать работу калькулятора следующей конструкции:

 в вычислении участвуют целые числа объемом памяти 2 байта;
 допустимые операции: +, -, *, / (целочисленное деление), % (деление с остатком), << (побитовый сдвиг влево), >> (побитовый сдвиг в право);
 операции выполняются последовательно, для выполнения операции необходимы два аргумента и знак операции;
 после выполнения каждой операции фиксируется и выводится результат;
 последовательность операций и аргументов образует выражение;
 результат отображается в 16, 10 и 2-ой системе счисления;
 при возникновении переполнения выдается Overflow;
 при попытке деления на 0 выдается Division by zero;
 при вводе знака “C” калькулятор приводиться в исходное состояние, первый аргумент выражения принимает значение 0 и готов для ввода очередного выражения;
 при вводе знака “Off” калькулятор завершает работу.
Нажатие на клавиши калькулятора моделируется посредством
клавиатурного ввода. Ввод делится на команды:
 «целое число» - первый аргумент выражения, целое не отрицательное число, можно последовательно вводить несколько раз, предыдущее значение меняется. При вводе не первым аргументом выражения - игнорируется;
 «знак операции» «целое число» - второе и последующие операции выражения;
 «C» - приведение калькулятора в исходное состояние;
 «Off» - завершение работы калькулятора.

Вывод результата моделируется посредством вывода на консоли. Результат выводиться в следующей форме:
      «выражение»     HEX «16-ое число»  DEC «10-ое число»  BIN «2-ое число»
«16-ое число» выводиться в верхнем регистре с лидирующими нулями (пример 01FA).
«10-ое число» (пример 1765).
«2-ое число» выводиться разбивкой по четыре цифры с лидирующими нулями (пример 0000 0100 0111 0101).


**Построить систему, которая использует объекты:**
1. Объект «система».
2. Объект для чтения команд. После чтения очередной команды объект выдает сигнал с текстом, содержащим команду. Все команды синтаксический корректны (моделирует пульт управления калькулятора).
3. Объект для выполнения арифметических операции. После завершения выдается сигнал с текстом результата. Если произошло переполнение или деление на нуль, выдается сигнал об ошибке. После выдачи сообщения калькулятор переводится посредством соответствующего сигнала в исходное положение.
4. Объект для выполнения операции побитового сдвига. После завершения выдается сигнал с текстом результата.
5. Объект для выполнения операции «C».
6. Объект для вывода очередного результата на консоль.
Написать программу, реализующую следующий алгоритм:
1. Вызов метода объекта «система» build_tree_objects ( ).
1.1. Построение дерева иерархии объектов.
1.2. Установка связей сигналов и обработчиков между объектами.
2. Вызов метода объекта «система» exec_app ( ).
2.1. Приведение всех объектов в состояние готовности.
2.2. Цикл для обработки вводимых команд.
2.2.1. Выдача сигнала объекту для ввода команды.
2.2.2. Отработка команды.
2.3. После ввода команды «Off» завершить работу.
Все приведенные сигналы и соответствующие обработчики должны быть
реализованы.
Все сообщения на консоль выводятся с новой строки.
В набор поддерживаемых команд добавить команду «SHOWTREE» и по
этой команде вывести дерево иерархии объектов системы с отметкой о готовности и завершить работу программы.

