from cs50 import get_float


def coins_count(change):
    coins =0
    amt = round(change * 100)
    while amt >= 25:
        coins += 1
        amt -= 25
    while amt >= 10:
        coins += 1
        amt -= 10
    while amt >= 5:
        coins += 1
        amt -= 5
    while amt >= 1:
        coins += 1
        amt -= 1
    print(coins)

while True:
    change = get_float("Enter the change : ")
    if change > 0:
        break

coins_count(change)
