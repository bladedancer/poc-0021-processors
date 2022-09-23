FROM golang:alpine3.16 as builder

RUN mkdir -p /go/src/github.com/bladedancer/processors/service

WORKDIR /go/src/github.com/bladedancer/processors/service

# Copy necessary files
ADD . .

RUN rm -rf bin
RUN CGO_ENABLED=0 GOOS=linux  GOARCH=amd64 go build -o bin/ext_proc ./

# Create non-root user
RUN addgroup -S axway && adduser -S axway -G axway
RUN chown -R axway:axway /go/src/github.com/bladedancer/processors/service/bin/ext_proc
USER axway

# Base image
FROM scratch

# Copy binary and user from previous build step
COPY --from=builder /etc/ssl/certs/ca-certificates.crt /etc/ssl/certs/ca-certificates.crt
COPY --from=builder /go/src/github.com/bladedancer/processors/service/bin/ext_proc /root/ext_proc
COPY --from=builder /etc/passwd /etc/passwd
USER axway

ENTRYPOINT ["/root/ext_proc"]