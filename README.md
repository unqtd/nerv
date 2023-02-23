# nerv

![Статус проекта - Реализация базового функционала](https://img.shields.io/badge/Статус_проекта-Реализация_базового_функционала-informational)
![C - 90](https://img.shields.io/badge/C-90-2ea44f)

HAL-о подобное нечто созданное за время прохождения курса по программированию МК AVR в 
техникуме. Возможно пригодится в будущем, но это не мой конек. В любом случае это 
игрушечный учебный проект, не для промышленного использования!

P.S. Еще прохожу курс...

## Установка

<!-- Библиотека не является отдельной единицей компиляции, она состоит из одних  -->
<!-- . Это было сделано намерено, так как таким образом компилятор -->
<!-- сможет производить constant evaluation и inlining, убирая весь лишний оверхед.  -->

Чтобы начать использовать nerv, просто скопируйте репозиторий себе в проект:
```
$ git clone https://github.com/dx3mod/nerv.git && rm -rf ./nerv/.git
```

Если вы пользуйтесь [yug](https://github.com/dx3mod/yug), то поместите файлы в 
директорию `vendor`:
```
$ git clone https://github.com/dx3mod/nerv.git vendor/nerv && rm -rf ./vendor/nerv/.git
```

## Поддерживаемые МК

| ATtiny      | ATmega |
|-------------| ------ |
| attiny2313a |        |
| attiny13a   |        |


## Документация

Основное:
* [Руководство по использованию](./docs/guide.md)
* [Узкие места](./docs/bottlenecks.md)

Дополнительное:
* [Как добавить поддержку для вашего микроконтроллера?](./docs/how_to_add_new_support_for_your_microcontroller.md) — для тех, кто хочет использовать nerv, но его микроконтроллер не поддерживается из коробки. 

## References 

* [MicroCore](https://github.com/MCUdude/MicroCore)

## To-Do 

Первый этап:
- [X] `digital_write`, `digital_read`
- [X] `analog_write`
- [ ] `analog_read`

Следующий этап:
- [ ] `shiftIn`, `shiftOut`

...
