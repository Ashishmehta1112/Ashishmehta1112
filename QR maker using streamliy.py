# import the streamlit library

import streamlit as st

import pyqrcode 

from PIL import Image

# give a title to our app

a=st.title('Welcome to QR MAKER')

 


        


            
websitename= st.text_input("Type the website name for which you want to make qr code")

 

# check if the button is pressed or not

if(st.button('Make QR')):

 

 

# String which represents the QR code website name is the string 

  a=len(websitename)

  if(a!=0):

# Generate QR code 

    url = pyqrcode.create(websitename)

  

# Create and save the svg file naming "myqr.svg"

    url.svg("myqr.svg", scale = 8)

  

# Create and save the png file naming "myqr.png"

    url.png('myqr.png', scale = 6)

#open"myqr.png"

    image1 =     Image.open('myqr.png') 

    st.image(image1)

  

  

   

if(len(websitename)==0):

  st.warning("no url given")

  

