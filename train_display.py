import json
import matplotlib.pyplot as plt
import matplotlib.patches as patches

def read_train(filename):
    with open(filename) as f:
        train = json.load(f)
    return train

import matplotlib.pyplot as plt
import matplotlib.patches as patches

def draw_locomotive(ax, train, plank_length, plank_height, nail_size):
    locomotive_end = (len(train['locomotive']['planks']) - 1) * plank_length
    ax.plot([0, 0], [0, plank_height], color='red')
    ax.plot([locomotive_end, locomotive_end], [0, plank_height], color='red')
    for j in range(len(train['locomotive']['planks']) - 1):
        ax.plot([j * plank_length, (j + 1) * plank_length], [0, 0], color='red')
        ax.add_patch(patches.Circle((j * plank_length, 0), nail_size, facecolor='black'))
        ax.plot([j * plank_length, (j + 1) * plank_length], [plank_height, plank_height], color='red')
        ax.add_patch(patches.Circle((j * plank_length, plank_height), nail_size, facecolor='black'))
    ax.add_patch(patches.Circle((locomotive_end, 0), nail_size, facecolor='black'))
    ax.add_patch(patches.Circle((locomotive_end, plank_height), nail_size, facecolor='black'))
    ax.plot([locomotive_end, locomotive_end + plank_length], [plank_height/2, plank_height/2], color='black')
    return locomotive_end + plank_length

def draw_wagons(ax, train, wagon_start, plank_length, plank_height, nail_size):
    for i, wagon in enumerate(train['wagons'], start=1):
        wagon_end = wagon_start + (len(wagon['wagon']['planks']) - 1) * plank_length
        ax.plot([wagon_start, wagon_start], [0, plank_height], color='brown')
        ax.plot([wagon_end, wagon_end], [0, plank_height], color='brown')
        for j in range(len(wagon['wagon']['planks']) - 1):
            ax.plot([wagon_start + j * plank_length, wagon_start + (j + 1) * plank_length], [0, 0], color='brown')
            ax.add_patch(patches.Circle((wagon_start + j * plank_length, 0), nail_size, facecolor='black'))
            ax.plot([wagon_start + j * plank_length, wagon_start + (j + 1) * plank_length], [plank_height, plank_height], color='brown')
            ax.add_patch(patches.Circle((wagon_start + j * plank_length, plank_height), nail_size, facecolor='black'))
        ax.add_patch(patches.Circle((wagon_end, 0), nail_size, facecolor='black'))
        ax.add_patch(patches.Circle((wagon_end, plank_height), nail_size, facecolor='black'))
        if wagon['passengerCount'] > 0:
            draw_passengers(ax, wagon, wagon_start, wagon_end, plank_height)
        if i < len(train['wagons']):
            ax.plot([wagon_end, wagon_end + plank_length], [plank_height/2, plank_height/2], color='black')
        wagon_start = wagon_end + plank_length
    return wagon_start

def draw_passengers(ax, wagon, wagon_start, wagon_end, plank_height):
    passenger_spacing = (wagon_end - wagon_start) / (wagon['passengerCount'] + 1)
    for j in range(wagon['passengerCount']):
        ax.add_patch(patches.Circle((wagon_start + (j + 1) * passenger_spacing, plank_height/2), 20, facecolor='green'))

def draw_train(train):
    fig, ax = plt.subplots(figsize=(10, 5))
    ax.set_aspect('equal')
    ax.axis('off')

    plank_length = 300
    plank_height = 2000
    nail_size = 50

    wagon_start = draw_locomotive(ax, train, plank_length, plank_height, nail_size)
    draw_wagons(ax, train, wagon_start, plank_length, plank_height, nail_size)

    plt.show()

if __name__ == "__main__":
    filepath_1 = 'cmake-build-debug/Trains/Train_one.json'
    train = read_train(filepath_1)
    draw_train(train)