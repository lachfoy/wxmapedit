#include "ImageLoader.h"

#include <err.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

wxImage ImageLoader::loadImage(const char* path)
{
    int x, y, n;
    unsigned char *data = stbi_load(path, &x, &y, &n, 0);

    if (!data)
    {
        fprintf(stderr, "errow working?: %s\n", stbi_failure_reason());
    }

    printf("Loaded tile image data\n");
    printf("x: %i\n", x);
    printf("y: %i\n", y);
    printf("n: %i\n", n);

    // wxImage(int width, int height, unsigned char *data, bool static_data=false)
    wxImage image = wxImage(x, y, data);

    //stbi_image_free(data);

    return image;
}