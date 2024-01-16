import json
import matplotlib.pyplot as plt
import matplotlib.patches as patches

def read_train(filename):
    with open(filename) as f:
        train = json.load(f)
    return train

def draw_wheels(ax, wagon, wagon_start, plank_length, wheels_scale, wheels_offset):
    for j, plank in enumerate(wagon['wagon']['planks']):
        wheel_position = wagon_start + j * plank_length
        if plank['wheel'] > 0:
            wheel_radius = plank['wheel'] * wheels_scale
            ax.add_patch(patches.Circle((wheel_position, wheels_offset + wheel_radius), wheel_radius, facecolor='black'))
            ax.plot([wheel_position, wheel_position], [wheels_offset + wheel_radius, 0], color='black')  # Draw a line connecting the wheel to the bottom of the train # Draw a line connecting the wheel to the bottom of the train

def draw_locomotive(ax, train, plank_length, plank_height, nail_size, wheels_scale, wheels_offset):
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

    draw_wheels(ax, {'wagon': train['locomotive']}, 0, plank_length, wheels_scale, wheels_offset)

    return locomotive_end + plank_length


def draw_wagons(ax, train, wagon_start, plank_length, plank_height, nail_size, passenger_scale, wheels_scale, wheels_offset):
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
            draw_passengers(ax, wagon, wagon_start, wagon_end, plank_height, passenger_scale)
        draw_wheels(ax, wagon, wagon_start, plank_length, wheels_scale, wheels_offset)
        if i < len(train['wagons']):
            ax.plot([wagon_end, wagon_end + plank_length], [plank_height/2, plank_height/2], color='black')
        wagon_start = wagon_end + plank_length
    return wagon_start


def draw_passengers(ax, wagon, wagon_start, wagon_end, plank_height, passenger_scale):
    passenger_spacing = (wagon_end - wagon_start) / (len(wagon['passengers']) + 1)
    for j, passenger in enumerate(wagon['passengers']):
        # Draw the belly
        belly_scale = passenger['belly'] * passenger_scale
        ax.add_patch(patches.Circle((wagon_start + (j + 1) * passenger_spacing, plank_height/2), belly_scale, facecolor='blue'))
        # Draw the head
        head_scale = passenger['head'] * passenger_scale
        ax.add_patch(patches.Circle((wagon_start + (j + 1) * passenger_spacing, plank_height/2 + belly_scale), head_scale/2, facecolor='green'))

def draw_train(train):
    fig, ax = plt.subplots(figsize=(10, 5))
    ax.set_aspect('equal')
    ax.axis('off')

    plank_length = 100
    plank_height = 500
    nail_size = 10
    passenger_scale = 10
    wheels_scale = 10  # Add this line
    wheels_offset = -100  # Add this line

    wagon_start = draw_locomotive(ax, train, plank_length, plank_height, nail_size, wheels_scale, wheels_offset)
    draw_wagons(ax, train, wagon_start, plank_length, plank_height, nail_size, passenger_scale, wheels_scale, wheels_offset)  # Modify this line

    plt.show()

def draw_passengers(ax, wagon, wagon_start, wagon_end, plank_height, passenger_scale):
    passenger_spacing = (wagon_end - wagon_start) / (len(wagon['passengers']) + 1)
    for j, passenger in enumerate(wagon['passengers']):
        # Draw the belly
        belly_scale = passenger['belly'] * passenger_scale
        ax.add_patch(patches.Circle((wagon_start + (j + 1) * passenger_spacing, plank_height/2), belly_scale, facecolor='blue'))
        # Draw the head
        head_scale = passenger['head'] * passenger_scale
        ax.add_patch(patches.Circle((wagon_start + (j + 1) * passenger_spacing, plank_height/2 + belly_scale), head_scale/2, facecolor='green'))

def draw_train(train):
    fig, ax = plt.subplots(figsize=(10, 5))
    ax.set_aspect('equal')
    ax.axis('off')

    plank_length = 100
    plank_height = 500
    nail_size = 10
    passenger_scale = 10
    wheels_scale = 10  # Add this line
    wheels_offset = -500  # Add this line

    wagon_start = draw_locomotive(ax, train, plank_length, plank_height, nail_size, wheels_scale, wheels_offset)
    draw_wagons(ax, train, wagon_start, plank_length, plank_height, nail_size, passenger_scale, wheels_scale, wheels_offset)  # Modify this line

    plt.show()

if __name__ == "__main__":
    filepath_1 = 'cmake-build-debug/Trains/Train_one.json'
    filepath_2 = 'cmake-build-debug/Trains/Train_two.json'
    train = read_train(filepath_1)
    draw_train(train)