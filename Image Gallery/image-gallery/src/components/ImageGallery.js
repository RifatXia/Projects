import React from 'react';
import './ImageGallery.css';

function ImageGallery(){
    const images = [
        '/product_images/image-1.webp'
    ]

    return(
        <div className='image-gallery'>
            {images.map((imageUrl, index) => (
                <div key={index} className={`image ${index === 0 ? 'feature-image' : ''}`}>
                    <img src={imageUrl} alt={`Image ${index + 1}`} />
                </div>
            ))}
        </div>
    );
}
export default ImageGallery;