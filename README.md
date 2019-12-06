# Reversible_Blurring_and_Selective_Encryption

# CONTEXT

Encrypting images with efficient encryption algorithms like AES can cause problems when we are not trying to completely hide the content of the image.

A solution to this problem is to use a less degrading method which creates the illusion of a blur.

This project's goal is to apply a a permutation algorithm to prevent from completely losing sight of the content of the image.

# REVERSIBLE BLURRING

This algorithm permutes 2 successive pixels blocks of size K: *0 < K < min(Height, Width)*

# SELECTIVE ENCRYPTION

The purpose of reversible blurring is to protect some informations in an image. This doesn't mean we need to blur the whole image. 
Like blurring a face to protect the identity of someone (security footages), or masking a brand logo in a TV Show.

To do this, we just need to apply the previous permutation algorithm but only on a specified area of the image by applying a binary image (mask)

# CREDITS AND REFERENCES

This model was created as part of a research project at the Faculty of Sciences of the University of Montpellier by Ines Benghezal and Yasmine Khodja.

### Copyright (c) 2019 Inès Benghezal and Yasmine Khodja. All rights reserved.
