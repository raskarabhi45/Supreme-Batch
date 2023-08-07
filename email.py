import smtplib
import time
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart

# Function to send email
def send_email(sender_email, sender_password, receiver_email, subject, body):
    try:
        # Set up the SMTP server
        server = smtplib.SMTP('smtp.gmail.com', 587)
        server.starttls()

        # Login to the sender's email account
        server.login(sender_email, sender_password)

        # Create the email message
        message = MIMEMultipart()
        message['From'] = sender_email
        message['To'] = receiver_email
        message['Subject'] = subject
        message.attach(MIMEText(body, 'plain'))

        # Send the email
        server.sendmail(sender_email, receiver_email, message.as_string())

        # Close the connection
        server.quit()

        print("Email sent successfully!")

    except Exception as e:
        print("Error sending email:", e)

# Main function
def main():
    # Set the sender's email and password
    sender_email = "raskarabhi45@gmail.com"
    sender_password = "Abhi@1245"

    # Set the receiver's email
    receiver_email = "omkarmhaske45@.com"

    # Set the email subject and body
    subject = "Automated Email"
    body = "This is an automated email sent using Python."

    # Set the time for sending the email (24-hour format)
    send_time_hour = 14  # 2 PM
    send_time_minute = 30

    while True:
        # Get the current time
        current_time = time.localtime()

        # Check if it's the specified time to send the email
        if (
            current_time.tm_hour == send_time_hour
            and current_time.tm_min == send_time_minute
        ):
            # Send the email
            send_email(sender_email, sender_password, receiver_email, subject, body)

            # Wait for one day before sending the email again
            time.sleep(24 * 60 * 60)

        # Wait for 1 minute before checking again
        time.sleep(60)

if __name__ == "__main__":
    main()
