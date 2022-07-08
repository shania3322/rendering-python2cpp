from dataclasses import dataclass
from typing import Tuple, List

@dataclass
class Vector2:
    x: int
    y: int

@dataclass
class Vector3:
    x: int
    y: int
    z: int

@dataclass
class Line2D:
    line: List[Vector2, Vector2]

@dataclass
class triangle2D:
    triangle: List[Vector2, Vector2, Vector2]
