from PIL import Image, ImageDraw, ImageFont

# Function to convert text to title case
def to_title_case(text):
    return ' '.join(word.capitalize() for word in text.split())

# Input PNG image
input_image_path = "Certificate Writer/certificate.png"
# Font path (replace with the path to your "Great Vibes" OTF file)
font_path = "Certificate Writer/fonts/GreatVibes-Regular.otf"

# Read the list of names from a text file
with open("Certificate Writer/names.txt", "r") as file:
    names = file.read().splitlines()

# Output folder for certificates
output_folder = "Certificate Writer/output/"

# Create the output folder if it doesn't exist
import os
os.makedirs(output_folder, exist_ok=True)

# Load the input image
image = Image.open(input_image_path)

# Load the "Great Vibes" OTF font
font_size = 100  # You can adjust the font size as needed
font = ImageFont.truetype(font_path, font_size)

# Define the desired y-coordinate
y = 550

# Iterate through the list of names, convert to title case, and create individual certificates
for name in names:
    # Convert the name to title case
    title_case_name = to_title_case(name)

    # Create a copy of the input image
    certificate = image.copy()

    # Create a drawing context for adding text to the copy
    draw = ImageDraw.Draw(certificate)

    # Calculate the x-coordinate for center alignment
    text_width, text_height = draw.textsize(title_case_name, font=font)
    image_width, image_height = certificate.size
    x = (image_width - text_width) // 2

    # Add the name in title case to the certificate with center alignment
    draw.text((x, y), title_case_name, fill="black", font=font)

    # Save the individual certificate
    certificate.save(os.path.join(output_folder, f"{title_case_name}.png"))

print("Certificate generation completed.")