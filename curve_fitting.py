import numpy as np
import matplotlib.pyplot as plt
from numpy.linalg import lstsq

wavelength = 660e-9             #Lens and wave properties
k = 2 * np.pi / wavelength
n = 1.5168
A0 = 0.005e-3
R1 = 0.113696e-3
R2 = 10000

size = 101                      #  Grid of x, y
x = np.linspace(-15e-6, 15e-6, size)
y = np.linspace(-15e-6, 15e-6, size)
X, Y = np.meshgrid(x, y)

rho = np.sqrt(X**2 + Y**2)         # Radial distance ρ and normalize it
M = np.max(rho)
rho_norm = rho / M

term1 = k * n * A0                    # Phase φ(x, y) from lens formula
term2 = k * (n - 1) * R1 * (1 - np.sqrt(1 - (rho**2 / R1**2)))
term3 = k * (n - 1) * R2 * (1 - np.sqrt(1 - (rho**2 / R2**2)))
phi = term1 - term2 + term3

phi_center = phi[size // 2, size // 2]     #Center phase subtraction (make φ(0) = 0)
phi_rel = phi - phi_center

X_fit = np.vstack([                   # Create polynomial features
    rho_norm.ravel() ** 2,
    rho_norm.ravel() ** 4,
    rho_norm.ravel() ** 6
]).T
y_fit = phi_rel.ravel()

coeffs, _, _, _ = lstsq(X_fit, y_fit, rcond=None)        #  Solve for coefficients A1, A2, A3
A1, A2, A3 = coeffs

phi_fitted = (A1 * rho_norm**2 +
              A2 * rho_norm**4 +          # Build fitted phase φ(ρ)
              A3 * rho_norm**6)


fig, axs = plt.subplots(1, 2, figsize=(12, 5))      # Plot original and fitted phase maps

c1 = axs[0].imshow(phi_rel * 1e6, cmap='viridis', extent=(-15, 15, -15, 15))
axs[0].set_title("Original Phase φ(x, y)")
axs[0].set_xlabel("x (μm)")
axs[0].set_ylabel("y (μm)")
plt.colorbar(c1, ax=axs[0], label='μrad')

c2 = axs[1].imshow(phi_fitted * 1e6, cmap='viridis', extent=(-15, 15, -15, 15))
axs[1].set_title("Fitted Polynomial Phase")
axs[1].set_xlabel("x (μm)")
axs[1].set_ylabel("y (μm)")
plt.colorbar(c2, ax=axs[1], label='μrad')

plt.tight_layout()
plt.show()

# Print final result
print("Fitted coefficients:")
print("A1 =", A1)
print("A2 =", A2)
print("A3 =", A3)
