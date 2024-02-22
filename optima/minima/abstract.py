from collections.abc import Iterable
from abc import abstractmethod
from math import sqrt

class Func:
  @abstractmethod
  def __init__(self):
    pass
  
  @abstractmethod
  def __call__(self) -> float:
    pass
  
  @abstractmethod
  def random_point(self) -> Iterable[float]:
    pass
  
  @abstractmethod
  def domain_width(self) -> float:
    pass
  
  
class Agent:
  def __init__(self, func: Func, point: Iterable[float] = None):
    if not point:
      point = func.random_point()
    self.point = point
    self.val = func(point)
    
  def l1_dist(self, other: Iterable[float]) -> float:
    return sum(abs(c1 - c2) for c1, c2 in zip(self.point, other))
    
  def l2_dist(self, other: Iterable[float]) -> float:
    return sqrt(sum((c1 - c2) ** 2 for c1, c2 in zip(self.point, other)))

  def l_inf_dist(self, other: Iterable[float]) -> float:
    return max(abs(c1 - c2) for c1, c2 in zip(self.point, other))
    
