## Задача
Реализирайте система за управление на библиотека:
- Структура **Book** със следните полета:
    - title (низ)
    - author (низ)
    - publicationYear (int)
    - status (enum: Available, Borrowed, Reserved)
- Структура **Library**, която съдържа:
    - name (низ)
    - Масив от Book (максимум 10 книги)
    - bookCount (брой налични книги)
- Функции:
    - addBook(Library&, const char*, const char*, int) – добавя книга в библиотеката.
    - borrowBook(Book&) – маркира книга като заета.
    - reserveBook(Book&) – маркира книга като резервирана.
    - printLibrary(const Library&) – извежда всички книги и техния статус.
