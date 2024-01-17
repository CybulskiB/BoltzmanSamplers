import math

from numpy.random import logseries


class WheelSampler:
    def __init__(self):
        self.wheel_elem_sampler = WheelElemSampler()

    def gen_func(self, x):
        return math.log(1 / (1 - self.wheel_elem_sampler.gen_func(x)))

    def sample(self, x):
        return cycle_sampler(
            combinatorial_class=self.wheel_elem_sampler,
            x=x,
        )


class WheelElemSampler:
    def gen_func(self, x):
        return x

    def sample(self, x):
        return "w"


def cycle_sampler(combinatorial_class, x):
    cycle_length = logseries(p=combinatorial_class.gen_func(x), size=1)[0]

    return [combinatorial_class.sample(x) for _ in range(cycle_length)]


# print(wheel(0.99))
wheel = WheelSampler(3)
print(wheel.sample(0.7))\



