Некоторые особенности выполнения ДЗ
При выполнении задания должны быть учтены следующие требования.
1. Для классов объектов явно определяются и разрабатываются: конструкторы (не менее двух для каждого класса) и деструкторы (для каждого класса);
   Пример. Конструкторы могут с первоначальным заданием параметров или нет, например,
   с заданием названия улицы и т.д.
2. В каждом классе помимо конструкторов и деструкторов должны быть определены не
   менее четырех методов (функций членов класса) и не менее четырех свойств (данных класса);
   Пример. Методы для улиц могут быть такими: добавление дома, удаление дома, распечатки домов улицы, нумерация домов, сложение улиц, деление улиц и т.д. Например,
   деление улицы на две может интерпретироваться так: первые N домов переносятся на
   "улицу Горького", а остальные на "Тверскую". Т.е., другими словами, из одного объекта
   мы получаем два других объекта с определенными свойствами. Разрабатывая такую операцию нужно продумать вопросы: где создаются новые объекты, как они заполняться,
   уничтожается ли исходный объект и т.д.
3. В одном классе по выбору, в зависимости от варианта, определяется как минимум
   одна перегружаемая операция (обязательная операция, обозначенная знаком "+" ).
   Пример. Добавление дома к улице – Street1+Home1;.
4. Описания классов должны быть вынесены в отдельные файлы (*.h). При этом необходимо исключить повторное включение описаний в исходный текст.
   Пример. Например, с помощью переменных этапа компиляции (define __STREET_H):
5. Обязательным является перегрузка операции вывода (<<) в стандартный поток cout
   для предметного класса
   Задание
   


Разработать программу, работающую с объектами классов. Используя интерфейс
   командной строки, реализовать следующие режимы работы: «Ввод нового объекта и добавление его в контейнер», «Поиск объекта в контейнере по значениям полей с печатью
   данных о найденных объектах», «Редактирование объекта», «Удаление объекта из контейнера», «Сохранение данных всех объектов в файле», «Чтение данных объектов из
   файла», «Сортировка объектов контейнера по выбранному полю для list», «Печать списка
   объектов». Предусмотреть обработку исключений, возможные исключения определить
   самостоятельно. В функции main должен быть главный поток, который создает консольное меню для выбора режима, режимы, требующие взаимодействия с пользователем
   (ввод нового объекта, редактирование объекта, поиск и печатью, печать списка объектов
   и т.п.) выполняются в этом главном потоке. Режимы, не требующие взаимодействия с
   пользователем (удаление, сохранение в файле и чтение из файла), выполняются в отдельном потоке, созданном в главном, при этом обеспечить синхронизацию при доступе к
   данным объектов


Наш Вариант :
Класс студентов и класс учебных групп для учета успеваемости по итогам одного семестра, предусмотреть расчет
среднего балла для группы по всем дисциплинам и по отдельной дисциплине, печать отличников и задолженников.

##### (по мере выполнения пунктов ниже зачеркиваем их, а не удаляем)

## ОШИБКИ, которые были найдены:


## ЗАДАЧИ, что добавить или изменить
  _**0. Возможно, удалить addStudent() метод**_
 1. Подумать над разграничением диапазонов ID. Обновить конструкторы Studetn
 2. Ищбавиться от students_amount в констркторе. Пусть оно вычисляется основываясь на размере вектора. 
 3. Проверить перегрузку Group + Student
 4. Возможно стоит везде хранить указатели, а не сами элементы класса, как например в классе Group, мы храним элементы Student, а если мы будем хранить, только указатель на студента, это упростит нам дальнейшую работу, плюс меньше время работы. 
 5. Сделать везде работу с айдишниками вместо других элементов
 #№ 6. ВАЖНАЯ ЗАДАЧА поменять в Group students с вектора на мэп
 
