# Игра в Блекджек

Этот проект представляет собой консольную версию известной карточной игры Блекджек на С++.

## Правила игры

1. Цель игры - набрать сумму очков близкую к 21, но не превышающую её.
- Карты от 2 до 10 имеют стоимость, равную их номиналу(например, карта '7' стоит 7 очков).
- Валет(J), дама(Q) и король(K) также стоят 10 очков каждый.
- Туз(A) может стоить 1 или 11 очков, в зависимости от ситуации.Он автоматически выбирается так, чтобы обеспечить наилучшую возможную комбинацию карт для игрока.
2. Игрок и дилер получают по две карты. У игрока обе карты открыты, у дилера одна открыта, а другая - закрыта.
3. Игрок ходит первым, может взять дополнительные карты или остаться при текущей сумме очков.
4. Дилер продолжает брать карты, пока сумма его очков меньше 17.
5. Победитель определяется по сумме очков, приближенной к 21.

## Определение победителя

- Если у игрока больше 21 очка, то программа выдает: "Вы проиграли, перебор!".
- Если у игрока очков меньше 21, но больше чем у дилера, то программа выдает: "Вы победили! Поздравляем!".
- Если у игрока меньше очков чем у дилера, то программа выдает "Вы проиграли! Удачи в следующий раз!".
- Если количесво очков одинаковое у игрока и у дилера, то программа выдает: "Ничья! Конец игры!".

## Пример игры
Когда перебор очков
![image](https://github.com/CleverCa/Practica/assets/147316700/e821da2b-b81f-4b1d-b9f4-a5bad7507956)

Когда победил игрок
![image](https://github.com/CleverCa/Practica/assets/147316700/c329490a-8edb-41a2-a72e-3f54e44c7c22)

Когда победил дилер
![image](https://github.com/CleverCa/Practica/assets/147316700/5b64956c-21ac-457a-bcec-c19b3c9d08ec)


