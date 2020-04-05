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

# Rolling Resistance
  * Rolling Resistance Coefficient formula:
      RollingResistance = RRCoefficient * NormalForce

      NormalForce:
        * F - Force due to gravity
        * m - mass of the object
        * g - acceleration due to gravity

              F = m*g

# Steering and Turning Circle

    TurningCircle:
      * dx  - delta movement
      * dΘ  - delta theta
      * r   - radius

            dΘ = dx / r


# Server Functions & Cheat Protection

  * RPC :   UFUNCTION(Server, Reliable, WithValidation)

# AutonomousProxy vs SimulatedProxy

# Sources Of Simulation Error

# Replicating Variables From The Server

# Triggering Code On Replication

# Smooth Simulated Proxies

# Simulating Lag And Packet Loss

# Replay Autonomous Moves

# Planning Client-Side Prediction

# Replicating Structs

# Simulating A Move

# Unacknowledged Move Queue
