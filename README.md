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

# Simulating Air Resistance
  AirResistance = -Speed² * DragCoefficient
  AirResistance / Speed² = DragCoefficient
        10,000 N /  25² m/s = DragCoefficient

  * Velocity - is a vector
    * it tells us about the direction and the magnitude
  * Speed - is a float
    * it tells us the magnitude of the velocity vector
