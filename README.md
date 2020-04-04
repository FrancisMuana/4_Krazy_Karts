# 4_Krazy_Karts
 State Synchronisation And Interpolation

# Creatiung A Go-Kart Pawn
  * Setup spring arm and camera
  * Made it move forward
    * Bind MoveForward keys

# How Things Move
  * F = Force
  * m = mass
  * a = acceleration

  * F = m * a
  * a = F / m

  * dx = delta x  // delta movement
  * dt = delta t  // delta time
  * v =           // velocity
  * a =           // acceleration
  * dv =          // Delta velocity

  * dx / dt = v
  * dx = v * dt
  * dv / dt = a
  * dv = a * dt

# Blocking Movement Without Physics
  * Reset the velocity to zero when hit something


# Apply Rotations With Quaternions
