# Sand Analytics

## Dense Prediction
In computer vision pixelwise **dense prediction** is the task of predicting a label for each pixel in the image. Dense prediction task is producing dense output for the given input. In computer vision, unlike image classfication, tasks such as semantic segmentation, instance segmentation, etc. are considered as dense prediction task because label for each pixel is predicted.
- [Dense Prediction on Sequences with Time-Dilated Convolutions for Speech Recognition
](https://arxiv.org/abs/1611.09288)



## Clip GeoTIFF into small patches
- **Source URL:** <https://gis.stackexchange.com/questions/437265/clip-geotiff-into-small-patches-using-rasterio-and-patchify-python> 
  - **Python Code**
    ```python
    import os, rasterio
    from rasterio.windows import Window
    from shapely.geometry import box
    import numpy as np


    def create_geopatches(
        image=None, x_size=None, y_size=None, x_overlap=0, y_overlap=0, output_path=None
    ):
        """
        Function to create georeferenced patches from a large georeferenced image. The function supports single-band
        and multi-band images. The patches will be created in the X and Y axis and the resulting patches will have the
        same bands as the input image. Images will be exported in GeoTiff format.

        Args:
            image (str): Path to the image which will be geopatchified.
            x_size (int): Patch size in X direction.
            y_size (int): Patch size in Y direction.
            x_overlap (int): Overlap between patches in X direction.
            y_overlap (int): Overlap between patches in Y direction.
            output_path (str): Path to the output directory. If None, they will be stored in the same path as image.

        Returns:
            Export images to disk in GeoTiff format.
        """
        base_name = os.path.splitext(os.path.basename(image))[0]
        if not os.path.exists(output_path):
            os.makedirs(output_path)
            print("New directory created at:", output_path)
        with rasterio.open(image) as src:
            original_width = src.width
            original_height = src.height
            num_patches_x = (original_width - x_overlap) // (x_size - x_overlap)
            num_patches_y = (original_height - y_overlap) // (y_size - y_overlap)
            c = 0
            print("num_patches_x :" + str(num_patches_x))  # 479
            print("num_patches_y :" + str(num_patches_y))  # 1019

            patches_to_create = num_patches_x * num_patches_y
            # for i in range(num_patches_x):
            for i in range(301, num_patches_x + 1):  # 400 done
                for j in range(num_patches_y):
                    c += 1
                    print("Processing:", c, "of", patches_to_create, "patches")
                    x_offset = i * (x_size - x_overlap)
                    y_offset = j * (y_size - y_overlap)
                    w = Window(x_offset, y_offset, x_size, y_size)
                    patch = src.read(window=w)
                    label = int(np.max(patch))
                    output_name = f"{base_name}_{i}_{j}.tif"
                    output_dir = os.path.join(output_path + str(label), output_name)
                    profile = src.meta
                    # print(profile)

                    profile.update(
                        {
                            "height": y_size,
                            "width": x_size,
                            "transform": src.window_transform(w),
                        }
                    )
                    print("Creating", output_name)
                    with rasterio.open(output_dir, "w", **profile) as dst:
                        dst.write(patch)
        print("Process successfully completed.")


    if __name__ == "__main__":
        create_geopatches(
            image="./data/138.tif", x_size=16, y_size=16, output_path="./data/138/"
        )


### practice : <https://courses.spatialthoughts.com/index.html>
    - https://www.kaggle.com/code/adudp007/loading-tiff-image-to-numpy-array
    - https://app.datacamp.com/learn/courses/deep-learning-for-images-with-pytorch

### Image segmentation:
- [Image Segmentation From Scratch in Pytorch](https://www.kaggle.com/code/dhananjay3/image-segmentation-from-scratch-in-pytorch)
- [Deep Learning Part 2 2018 - Super resolution; Image segmentation with Unet](https://www.youtube.com/watch?v=nG3tT31nPmQ)
  -[Semantic Segmentation using CNN](https://medium.com/@sharathhebbar24/semantic-segmentation-using-cnn-d35cf4a974c4)
