from copy import deepcopy as cp
import numpy as np
from abstract import Func, Agent


def select_sites(swarm, n, allow_intersections=True, env_size=None):
  if allow_intersections:
    return swarm[:n]
  else:
    i = 1
    selected = [swarm[0]]
    while len(selected) < n and i < len(swarm):
      for bee in selected:
        if swarm[i].l_inf_dist(bee.point) < env_size:
          break
      else:
        selected.append(swarm[i])
      i += 1
          

def bee_colony(func: Func, n_gener=1000, shrink_cf=0.9, n_scouts=100,
               n_elites=30, n_extras=10, n_elite_sites=5, n_extra_sites=15):
               
  n_total = n_scouts + n_elite_sites * n_elites + n_extra_sites * n_extras
  swarm = [Agent(func) for _ in range(n_total)]
  swarm.sort(key=lambda bee: bee.val)
  
  minima = cp(swarm[0])
  env_size = 2 * func.domain_width / (n_elite_sites + n_extra_sites)
  
  for gener in range(n_gener):
    for i in range(n_total):
      
  
  return minima
    