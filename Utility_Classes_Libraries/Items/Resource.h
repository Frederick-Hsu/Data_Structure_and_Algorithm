#ifndef RESOURCE_H
#define RESOURCE_H

    class Resource
    {
    public:
        Resource(params p);
        Resource(const Resource& res);
        Resource& operator=(const Resource& res);
        ~Resource();
    private:
        resource_type* r;       /* resource managed by this type */
        resource_type* allocate(params p);      /* allocate this resource */
        void release(resource_type*);       /* free this resource */
    };

#endif  /* RESOURCE_H */
