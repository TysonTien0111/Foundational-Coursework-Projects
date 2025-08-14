''''''
# dont forget to add docstrings
import random
import math


def main():
    ''''''
    seed = int(input('Enter the seed to run the fight with: '))
    random.seed(seed)
    attackers_hp = int(input("Enter the attacker's hp: "))
    attackers_strength = int(input("Enter the attacker's strength: "))
    attackers_accuracy = int(input("Enter the attacker's accuracy: "))
    attackers_crit_chance = int(input("Enter the attacker's crit chance: "))
    attackers_dodge_rate = int(input("Enter the attacker's dodge rate: "))
    attackers_normal_dmg = 0

    defenders_hp = int(input("Enter the defender's hp: "))
    defenders_strength = int(input("Enter the defender's strength: "))
    defenders_accuracy = int(input("Enter the defender's accuracy: "))
    defenders_crit_chance = int(input("Enter the defender's crit chance: "))
    defenders_dodge_rate = int(input("Enter the defender's dodge rate: "))

    is_defender_guarding = input('Is the defender guarding? Y for yes, n for no: ')
    gameplay(attackers_crit_chance, attackers_strength, defenders_hp, attackers_accuracy, defenders_dodge_rate,
             defenders_crit_chance, defenders_strength, attackers_hp, defenders_accuracy, attackers_dodge_rate,
             attackers_normal_dmg, is_defender_guarding)


def gameplay(attackers_crit_chance, attackers_strength, defenders_hp, attackers_accuracy, defenders_dodge_rate,
             defenders_crit_chance, defenders_strength, attackers_hp, defenders_accuracy, attackers_dodge_rate,
             attackers_normal_dmg, is_defender_guarding):
    attackers_critical_attack(attackers_crit_chance, attackers_strength, defenders_hp, attackers_accuracy,
                              defenders_dodge_rate, defenders_crit_chance, defenders_strength, attackers_hp,
                              defenders_accuracy, attackers_dodge_rate, attackers_normal_dmg, is_defender_guarding)


def attackers_critical_attack(attackers_crit_chance, attackers_strength, defenders_hp, attackers_accuracy,
                              defenders_dodge_rate, defenders_crit_chance, defenders_strength, attackers_hp,
                              defenders_accuracy, attackers_dodge_rate, attackers_normal_dmg, is_defender_guarding):
    attackers_crit_dmg = 0
    if attackers_critical_attack_hits(attackers_crit_chance):
        attackers_crit_dmg = attackers_strength + 1
        print(f'attacker crit defender for {attackers_crit_dmg} points of damage')
        if defenders_current_hp_from_crit(defenders_hp, attackers_crit_dmg) > 0:
            if is_defender_guarding == 'y' or is_defender_guarding == 'Y':
                defenders_counter_attack(defenders_crit_chance, defenders_strength, attackers_hp, defenders_accuracy,
                                     attackers_dodge_rate, defenders_hp, attackers_crit_dmg, attackers_normal_dmg,
                                     attackers_crit_chance)
            else:
                print('After fighting the attacker has', attackers_hp, 'hp left and the defender has',
                      defenders_current_hp_from_crit(
                          defenders_hp, attackers_crit_dmg), 'hp left')
        else:
            print('After fighting the attacker has', attackers_hp, 'hp left and the defender has', defenders_current_hp_from_crit(
                defenders_hp, attackers_crit_dmg), 'hp left')
    else:
        attackers_normal_attack(attackers_accuracy, defenders_dodge_rate, attackers_strength, defenders_hp,
                                defenders_crit_chance, defenders_strength, attackers_hp, defenders_accuracy,
                                attackers_dodge_rate, attackers_crit_dmg, attackers_crit_chance, is_defender_guarding)


def attackers_normal_attack(attackers_accuracy, defenders_dodge_rate, attackers_strength, defenders_hp,
                            defenders_crit_chance, defenders_strength, attackers_hp, defenders_accuracy,
                            attackers_dodge_rate, attackers_crit_dmg, attackers_crit_chance, is_defender_guarding):
    attackers_normal_dmg = 0
    if attackers_normal_attack_hits(attackers_accuracy):
        if defender_dodge(defenders_dodge_rate):
            print("defender dodged attacker's attack")
            defenders_counter_attack(defenders_crit_chance, defenders_strength, attackers_hp, defenders_accuracy,
                                     attackers_dodge_rate, defenders_hp, attackers_crit_dmg, attackers_normal_dmg,
                                     attackers_crit_chance)
        else:
            attackers_normal_dmg = random.randint(math.floor(attackers_strength / 2), attackers_strength)
            print(f'attacker hit defender for {attackers_normal_dmg} points of damage')
            if defenders_current_hp_from_normal_attack(defenders_hp, attackers_normal_dmg) > 0:
                if is_defender_guarding == 'y' or is_defender_guarding == 'Y':
                    defenders_counter_attack(defenders_crit_chance, defenders_strength, attackers_hp, defenders_accuracy,
                                         attackers_dodge_rate, defenders_hp, attackers_crit_dmg, attackers_normal_dmg,
                                         attackers_crit_chance)
                else:
                    print('After fighting the attacker has', attackers_hp, 'hp left and the defender has',
                          defenders_current_hp_from_normal_attack(
                              defenders_hp, attackers_normal_dmg), 'hp left')
            else:
                print('After fighting the attacker has', attackers_hp, 'hp left and the defender has', defenders_current_hp_from_normal_attack(
                    defenders_hp, attackers_normal_dmg), 'hp left')
    else:
        print('attacker missed defender')
        defenders_counter_attack(defenders_crit_chance, defenders_strength, attackers_hp, defenders_accuracy,
                                 attackers_dodge_rate, defenders_hp, attackers_crit_dmg, attackers_normal_dmg,
                                 attackers_crit_chance)

def attackers_critical_attack_hits(attackers_crit_chance):
    return random.random() < (attackers_crit_chance / 100)


def attackers_normal_attack_hits(attackers_accuracy):
    return random.random() < (attackers_accuracy / 100)


def defender_dodge(defenders_dodge_rate):
    return random.random() < (defenders_dodge_rate / 100)


def defenders_current_hp_from_crit(defenders_hp, attackers_crit_dmg):
    x = defenders_hp - attackers_crit_dmg
    if x > 0:
        return x
    else:
        return 0


def defenders_counter_attack(defenders_crit_chance, defenders_strength, attackers_hp, defenders_accuracy,
                             attackers_dodge_rate, defenders_hp, attackers_crit_dmg, attackers_normal_dmg,
                             attackers_crit_chance):
    defenders_critical_attack(defenders_crit_chance, defenders_strength, attackers_hp, defenders_accuracy,
                              attackers_dodge_rate, defenders_hp, attackers_crit_dmg, attackers_normal_dmg,
                              attackers_crit_chance)


def defenders_current_hp_from_normal_attack(defenders_hp, attackers_normal_dmg):
    x = defenders_hp - attackers_normal_dmg
    if x > 0:
        return x
    else:
        return 0


def defenders_critical_attack(defenders_crit_chance, defenders_strength, attackers_hp, defenders_accuracy,
                              attackers_dodge_rate, defenders_hp, attackers_crit_dmg, attackers_normal_dmg,
                              attackers_crit_chance):
    defenders_crit_dmg = 0
    if defenders_critical_attack_hits(defenders_crit_chance):
        defenders_crit_dmg = defenders_strength + 1
        print(f'defender crit attacker for {defenders_crit_dmg} points of damage')
        if attackers_critical_attack_hits(attackers_crit_chance):
            print('After fighting the attacker has', attackers_current_hp_from_crit(attackers_hp,
                                                                                     defenders_crit_dmg), 'hp left and the defender has', defenders_current_hp_from_crit(
                defenders_hp, attackers_crit_dmg), 'hp left')
        else:
            print('After fighting the attacker has', attackers_current_hp_from_crit(attackers_hp,
                                                                                     defenders_crit_dmg), 'hp left and the defender has', defenders_current_hp_from_normal_attack(
                defenders_hp, attackers_normal_dmg), 'hp left')
    else:
        defenders_normal_attack(defenders_accuracy, attackers_dodge_rate, attackers_hp, defenders_strength,
                                defenders_hp, attackers_crit_dmg, attackers_normal_dmg, attackers_crit_chance)


def attackers_current_hp_from_crit(attackers_hp, defenders_crit_dmg):
    x = attackers_hp - defenders_crit_dmg
    if x > 0:
        return x
    else:
        return 0


def defenders_critical_attack_hits(defenders_crit_chance):
    return random.random() < (defenders_crit_chance / 100)


def defenders_normal_attack(defenders_accuracy, attackers_dodge_rate, attackers_hp, defenders_strength, defenders_hp,
                            attackers_crit_dmg, attackers_normal_dmg, attackers_crit_chance):
    defenders_normal_dmg = 0
    if defenders_normal_attack_hits(defenders_accuracy):
        if attacker_dodge(attackers_dodge_rate):
            print("attacker dodged defender's attack")
            if attackers_critical_attack_hits(attackers_crit_chance):
                print('After fighting the attacker has', attackers_current_hp_from_normal_attack(attackers_hp,
                                                                                                  defenders_normal_dmg), 'hp left and the defender has', defenders_current_hp_from_crit(
                    defenders_hp, attackers_crit_dmg), 'hp left')
            else:
                print('After fighting the attacker has', attackers_current_hp_from_normal_attack(attackers_hp,
                                                                                                  defenders_normal_dmg), 'hp left and the defender has', defenders_current_hp_from_normal_attack(
                    defenders_hp, attackers_normal_dmg), 'hp left')
        else:
            defenders_normal_dmg = random.randint(math.floor(defenders_strength / 2), defenders_strength)
            print(f'defender hit attacker for {defenders_normal_dmg} points of damage')
            if attackers_critical_attack_hits(attackers_crit_chance):
                print('After fighting the attacker has', attackers_current_hp_from_normal_attack(attackers_hp,
                                                                                                  defenders_normal_dmg), 'hp left and the defender has', defenders_current_hp_from_crit(
                    defenders_hp, attackers_crit_dmg), 'hp left')
            else:
                print('After fighting the attacker has', attackers_current_hp_from_normal_attack(attackers_hp,
                                                                                                  defenders_normal_dmg), 'hp left and the defender has', defenders_current_hp_from_normal_attack(
                    defenders_hp, attackers_normal_dmg), 'hp left')
    else:
        print('defender missed attacker')
        if attackers_critical_attack_hits(attackers_crit_chance):
            print('After fighting the attacker has', attackers_current_hp_from_normal_attack(attackers_hp,
                                                                                              defenders_normal_dmg), 'hp left and the defender has', defenders_current_hp_from_crit(
                defenders_hp, attackers_crit_dmg), 'hp left')
        else:
            print('After fighting the attacker has', attackers_current_hp_from_normal_attack(attackers_hp,
                                                                                              defenders_normal_dmg), 'hp left and the defender has', defenders_current_hp_from_normal_attack(
                defenders_hp, attackers_normal_dmg), 'hp left')


def defenders_normal_attack_hits(defenders_accuracy):
    return random.random() < (defenders_accuracy / 100)


def attacker_dodge(attackers_dodge_rate):
    return random.random() < (attackers_dodge_rate / 100)


def attackers_current_hp_from_normal_attack(attackers_hp, defenders_normal_dmg):
    x = attackers_hp - defenders_normal_dmg
    if x > 0:
        return x
    else:
        return 0


main()
