# System Architecture

The Smart IoT Shopping Cart uses RFID technology to automate product identification and billing in retail environments.

## Components

- Arduino UNO
- RFID Reader (RC522)
- RFID Tags
- LCD Display
- Power Supply

## Workflow

1. Each product contains an RFID tag.
2. The RFID reader scans the tag when the product is placed in the cart.
3. Arduino reads the tag ID.
4. The system retrieves the corresponding product price.
5. The price is added to the running total.
6. The final bill is displayed when shopping is completed.

## Data Flow

RFID Tag → RFID Reader → Arduino → Price Calculation → Display Total Bill
